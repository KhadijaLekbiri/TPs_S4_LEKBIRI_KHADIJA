
#include "Server.hpp"



bool Server::allocate(double cpu, double memory) {
    Server::start();
    if (memory <= available_memory_ && cpu <= available_cpu_){
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    return false;
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


std::string Server::getMetrics() const {
    std::ostringstream cpuStream, memoryStream, availableCpuStream, availableMemoryStream;

    cpuStream << std::fixed << std::setprecision(0) << cpu_;
    memoryStream << std::fixed << std::setprecision(0) << memory_;
    availableCpuStream << std::fixed << std::setprecision(0) << available_cpu_;
    availableMemoryStream << std::fixed << std::setprecision(0) << available_memory_;

    return "[Server: " + id_ + ": " + cpuStream.str() + " CPU, " +
           memoryStream.str() + " Memory, Available: " +
           availableCpuStream.str() + " CPU, " +
           availableMemoryStream.str() + " Memory]";
}


std::ostream& operator<<(std::ostream& os, const Server& c){
    os << c.getMetrics();    
    return os;
};