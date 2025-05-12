#include "Server.hpp"
#include "CloudExceptions.hpp"


bool Server::allocate(double cpu, double memory) {
    Server::start();
    try {
        if (memory <= available_memory_ && cpu <= available_cpu_){
            available_cpu_ -= cpu;
            available_memory_ -= memory;
            return true;
        }
        throw AllocationException();
    }
    catch(const AllocationException& e){
        throw e;
    };
};

void Server::start() {
    if (!active_){
        active_ = true;
    }
};
void Server::stop() {
    if (active_){
        active_ = false;
    }
};
bool Server::isActive() const {
    return active_;
}

std::string Server::getMetrics() const {
    std::ostringstream cpuStream, memoryStream, availableCpuStream, availableMemoryStream;

    cpuStream << std::fixed << std::setprecision(1) << cpu_;
    memoryStream << std::fixed << std::setprecision(0) << memory_;
    availableCpuStream << std::fixed << std::setprecision(1) << available_cpu_;
    availableMemoryStream << std::fixed << std::setprecision(0) << available_memory_;

    return "[Server: " + id_ + " | Total: " + cpuStream.str() + " CPU, " + 
           memoryStream.str() + " MB | Free: " + availableCpuStream.str() + " CPU, " + 
           availableMemoryStream.str() + " MB]";
}


std::ostream& operator<<(std::ostream& os, const Server& c){
    os << c.getMetrics();    
    return os;
};