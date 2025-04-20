
#include "Container.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void Container::start() {
    if (!active_){
        active_ = true;
    }
};
void Container::stop() {
    if (active_){
        active_ = false;
    }
};
// std::string Container::getMetrics() const {
//     cout << std::fixed << std::setprecision(0);
//     return "[Container: "+id_+": "+to_string(cpu_)+" CPU, "+to_string(memory_)+" Memory, "+image_+"]"; 
// };

std::string Container::getMetrics() const {
    std::ostringstream cpuStream, memoryStream;

    cpuStream << std::fixed << std::setprecision(1) << cpu_; // I just changed the precision to 1 since in some statement it was 0 and in others it was 1
    memoryStream << std::fixed << std::setprecision(1) << memory_;

    return "[Container: " + id_ + ": " + cpuStream.str() + " CPU, " + memoryStream.str() + " Memory, " + image_ + "]";
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os <<c.getMetrics();
    return os;
}
