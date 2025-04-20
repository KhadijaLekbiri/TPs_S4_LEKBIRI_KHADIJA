#include "KubernetesCluster.hpp"


void display(const KubernetesCluster& cluster) {
    std::cout << "=== Cluster Metrics ===\n";
    std::cout << cluster;
}


void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods){
    for (auto& pod : pods) {
        cluster.deployPod(move(pod));
    }
};

