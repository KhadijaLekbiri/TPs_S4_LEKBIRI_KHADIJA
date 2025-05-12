#ifndef SERVER
#define SERVER

#include <iostream>
#include <string>
#include <iomanip>
#include "Resource.hpp"

using namespace std;

class Server: public Resource {
    private:
        double available_cpu_;
        double available_memory_;
    public:
        Server(std::string id, double cpu, double memory)
        : Resource(id, cpu, memory), available_cpu_(cpu), available_memory_(memory){};

        bool allocate(double cpu, double memory);
        void start() override;
        void stop() override;
        bool isActive() const;

        std::string getMetrics() const override;
        
        double get_available_memory_(){
            return available_memory_;
        };
        
        double get_available_cpu_(){
            return available_cpu_;
        };

        string get_id(){
            return id_;
        };

        friend std::ostream& operator<<(std::ostream& os, const Server& c);
        
        ~Server(){};
};
#endif
