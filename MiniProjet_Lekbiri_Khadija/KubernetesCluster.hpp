// #ifndef KubernetesCluster
// #define KubernetesCluster

#ifndef ACC
#define ACC

#include <iostream>
#include "Server.hpp"
#include "Pod.hpp"
#include <vector>
#include "memory"


class KubernetesCluster{
    private:
        vector<shared_ptr<Server>> nodes_;
        vector<unique_ptr<Pod>> pods_;
    public:
        KubernetesCluster(/* args */){};
        KubernetesCluster(KubernetesCluster&&) = default;  // Allow move construction
        KubernetesCluster& operator=(KubernetesCluster&&) = default;  // Allow move assignment
        void addNode(std::shared_ptr<Server> node);
        bool removePod(const std::string& name);
        void deployPod(std::unique_ptr<Pod> pod);
        bool schedulePod(Pod& pod);
        Pod* getPod(const std::string& name);
        std::string getMetrics() const;

        friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);

        ~KubernetesCluster(){};

};
#endif
