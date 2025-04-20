#ifndef RESOURCE
#define RESOURCE

#include <iostream>
#include <string>

using namespace std;

class Resource{
    protected:
        string id_;
        double cpu_;
        double memory_;
        bool active_;
    public:
        Resource(std::string id, double cpu, double memory)
        : id_(id), cpu_(cpu), memory_(memory), active_(false){};
        
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual std::string getMetrics() const = 0;
        ~Resource(){};
};
#endif