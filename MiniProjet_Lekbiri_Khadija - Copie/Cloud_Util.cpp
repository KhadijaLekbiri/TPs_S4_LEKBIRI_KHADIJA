#include "Cloud_Util.hpp"
#include "CloudExceptions.hpp"

#include <fstream>

void display(const KubernetesCluster& cluster) {
    std::cout << "=== Cluster Metrics ===\n";
    std::cout << cluster;
}


void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods){
    for (auto& pod : pods) {
        try {
            cluster.deployPod(move(pod));
        }
        catch(const AllocationException& e) {
            std::cerr << "Failed to deploy pod: " << e.what() << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << "Unexpected error during pod deployment: " << e.what() << std::endl;
        }
    }
    pods.clear(); // Clear the vector after attempting to deploy all pods
};

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename){
    std::ofstream file(filename);
    try {
       if (file.is_open()){
        file << cluster.getMetrics();
        cout<<"Métriques sauvegardées avec succès. \n";
       }
       else {
        throw FileException();
       }
    }
    catch(const FileException& e){
        std::cerr << e.what() << '\n';
    }
    
};

