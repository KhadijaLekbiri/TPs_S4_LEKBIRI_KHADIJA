
#include <iostream>
#include <vector>

using namespace std;

class StackFullException: public std::exception {
    public:
        StackFullException() = default;
        ~StackFullException() = default;

        const char* what() const noexcept override {
            return "Full Stack !";
        }
};

class StackEmptyException: public std::exception {
    public:
        StackEmptyException() = default;
        ~StackEmptyException() = default;

        const char* what() const noexcept override {
            return "Empty stack !!";
        }
};


class Stack {
    private:
        int capacity;
        vector<int> data;
    public:
        Stack(int c): capacity(c){};
        void push(int e){
            if (data.size() + 1 > capacity){
                throw StackFullException();
            }
            data.push_back(e);
        }

        void pop(){
            if (data.size() <= 1){
                throw StackEmptyException();
            }
            data.pop_back();
        }

        int size(){
            return capacity;
        }


};

void func_c(Stack s){
    s.push(0);
};

void func_b(Stack s){
    try{
        func_c(s);
    }
    catch(const StackFullException& ex){
        throw;
    }
};

void func_a(Stack s){
    try{
        func_b(s);
    }
    catch(const StackFullException& ex){
        throw;
    }
}


int main() {
    // Test 1: Demonstrating StackFullException via func_a
    try {
        Stack stack(2); // Stack with capacity of 2
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        func_a(stack); // Will throw StackFullException
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl; // Handling StackFullException
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl; // Handling unknown errors
    }

    // Test 2: Demonstrating StackEmptyException with pop
    try {
        Stack stack(2); // New empty stack
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.pop(); // Will throw StackEmptyException
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl; // Handling StackEmptyException
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl; // Handling unknown errors
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}