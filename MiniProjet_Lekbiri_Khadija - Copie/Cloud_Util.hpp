#ifndef CLOUD_UTIL
#define CLOUD_UTIL

#include "KubernetesCluster.hpp"
// #include "CloudExceptions.hpp"

void display(const KubernetesCluster& cluster);

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename);

#endif