#include <iostream>
#include "KubernetesCluster.hpp"
#include "CloudExceptions.hpp"
#include "Server.hpp"
#include "memory"
shared_ptr<Server> server_;

void KubernetesCluster::addNode(std::shared_ptr<Server> node){
    nodes_.push_back(node);
};


std::vector<Server*> KubernetesCluster::getFilteredServers(const std::function<bool(const Server&)>& func){
    std::vector<Server*> filteredServers;
    for (const auto& server : nodes_){
        if (func(*server)){
            filteredServers.push_back(server.get());
        }
    }
    return filteredServers;
};


bool KubernetesCluster::removePod(const std::string& name){
    
    for (auto it = pods_.begin(); it != pods_.end(); it++){
        if ((*it)->get_name() == name){
            pods_.erase(it);
            return true;
        }
    }
    return false;
};

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod){
    try {
        if(schedulePod(*pod)){
            cout << "-> Déploiement du Pod " <<*pod;
            pod->deploy();
            cout<<"sur le noeud "<<*server_<<" \nPod "<<*pod;
            std::cout << " déployé avec succès.\n";
            pods_.push_back(move(pod));
            return ;
        };
        throw AllocationException();
    }
    catch(const AllocationException &e){
        throw e;}
};



bool KubernetesCluster::schedulePod(Pod& pod){
    for (const auto& server : nodes_) {
        if (pod.get_memory() <= server->get_available_memory_() && pod.get_cpu() <= server->get_available_cpu_()) {
            server->allocate(pod.get_cpu(), pod.get_memory());
            server_ = server;
            return true;
        }
    }
    return false;
};

Pod* KubernetesCluster::getPod(const std::string& name){
    for (const auto& pod: pods_){
        if(pod->get_name() == name){
            return pod.get();
        }
    }
    return nullptr;
};

std::string KubernetesCluster::getMetrics() const {
    string metrics = "";
    int c = 0;
    for (const auto& server : nodes_) { 
        metrics += server->getMetrics() + "\n"; 
        c++;
    }
    for (const auto& pod : pods_) { 
        c++;
        metrics += pod->getMetrics();
    }
    return metrics;
};

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c){
    os<<c.getMetrics();
    return os;
};