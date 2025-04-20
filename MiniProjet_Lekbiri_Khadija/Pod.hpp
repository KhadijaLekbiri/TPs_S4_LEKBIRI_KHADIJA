#ifndef POD
#define POD


#include <iostream>
#include <string>
#include "Container.hpp"
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

class Pod {
    private:
        string name_;
        vector<unique_ptr<Container>> containers_;
        unordered_map<std::string, std::string> labels_;
    public:
        Pod(std::string name, std::unordered_map<std::string, std::string> labels = {})
        :name_(name), labels_(labels){};

        void addContainer(std::unique_ptr<Container> container);
        bool removeContainer(const std::string& id);
        void deploy();
        std::string getMetrics() const;
        string get_name(){
            return name_;
        }
        double get_memory(){
            double total_memory = 0.0;
            for (const auto& container : containers_) { 
                total_memory += container->get_memory(); 
            }
            return total_memory;
        }
        
        double get_cpu(){
            double total_cpu = 0.0;
            for (const auto& container : containers_) { 
                total_cpu += container->get_cpu(); 
            }
            return total_cpu;
        }

        friend std::ostream& operator<<(std::ostream& os, const Pod& p);
        const std::vector<std::unique_ptr<Container>>& getContainers() const;

        ~Pod(){};
};
#endif