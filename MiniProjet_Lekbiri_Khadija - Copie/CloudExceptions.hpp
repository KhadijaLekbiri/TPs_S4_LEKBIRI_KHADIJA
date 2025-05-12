#include <stdexcept>
#include <string>

using namespace std;

class CloudExceptions : public runtime_error {
public:
    CloudExceptions() : runtime_error("Cloud Exception !") {} // Pass message to base class
    ~CloudExceptions() = default;

    const char* what() const noexcept override {
        return "Cloud Exception !";
    }
};

class AllocationException : public CloudExceptions {
public:
    AllocationException() : CloudExceptions() {} // Explicitly invoke base class constructor
    ~AllocationException() = default;
    
    const char* what() const noexcept override {
        return "hanii !";
    }
};


class FileException: public CloudExceptions{
    public:
        FileException() = default; 
        ~FileException() = default;

        const char* what() const noexcept override {
            return "Error: Could not open or write to file";
        }
};
