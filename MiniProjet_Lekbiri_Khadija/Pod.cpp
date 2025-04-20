#include "Pod.hpp"
#include <vector>
#include <utility>
#include "string"
#include <iomanip>

using namespace std;

void Pod::addContainer(std::unique_ptr<Container> container){
    containers_.push_back(move(container));
};

bool Pod::removeContainer(const std::string& id) {
    for (auto it = containers_.begin(); it != containers_.end(); ++it) {
        if ((*it)->get_id() == id) {
            (*it)->stop();
            containers_.erase(it);
            labels_.erase(id);
            return true;
        }
    }
    return false;
}

void Pod::deploy(){
    for (const auto& container: containers_){
        container->start();
    }
};


std::string Pod::getMetrics() const {
    std::string result = "[Pod: " + name_ + "]\n";
    for (const auto& container : containers_) {
        result += container->getMetrics() + "\n";
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os <<p.getMetrics();
    return os;
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const{
    return containers_;
};

