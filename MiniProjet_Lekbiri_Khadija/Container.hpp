#ifndef CONTAINER
#define CONTAINER

#include <iostream>
#include <string>
#include "Resource.hpp"

using namespace std;

class Container: public Resource {
    protected:
        string image_;
    public:
        Container(std::string id, std::string image, double cpu, double memory)
        : Resource(id,cpu,memory), image_(image){};

        void start() override;
        void stop() override;

        std::string getMetrics() const override;

        string get_id(){
            return id_;
        };
        double get_cpu(){
            return cpu_;
        };
        double get_memory(){
            return memory_;
        };

        friend std::ostream& operator<<(std::ostream& os, const Container& c);

        ~Container(){};
};
#endif