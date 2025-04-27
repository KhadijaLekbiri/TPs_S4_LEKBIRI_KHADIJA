#include <iostream>


class NegativeQuantityException: public std::exception {
    public:
        NegativeQuantityException() = default;
        ~NegativeQuantityException() = default;

        const char* what() const noexcept override {
            return "You can not add negative quantity !";
        }
};

class InsufficientStockException: public std::exception {
    public:
        InsufficientStockException() = default;
        ~InsufficientStockException() = default;

        const char* what() const noexcept override {
            return "Insufficient Stock !";
        }
};

class Inventory {
    private:
        int stock;
    public:
        Inventory(int q) :stock(q){};

        int get_stock(){
            return stock;
        }

        void add_items(int q){
            if (q < 0){
                throw NegativeQuantityException();
            }
            stock += q;
        }

        void remove_items(int q){
            if (q >= stock){
                throw InsufficientStockException();
            }
            stock -= q;
        }

};

int main() {
    // Test 1: Initialization and adding items
    Inventory inv(100); // Initial stock of 100 items
    std::cout << "Initial stock: " << inv.get_stock() << std::endl;

    try {
        inv.add_items(50);
        std::cout << "After adding 50 items: " << inv.get_stock() << std::endl;
    } catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }

    // Test 2: Attempt to remove more items than available
    try {
        inv.remove_items(160); // Should throw InsufficientStockException
        std::cout << "After removing 160 items: " << inv.get_stock() << std::endl;
    } catch (const InsufficientStockException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }

    // Test 3: Attempt to add a negative quantity
    try {
        inv.add_items(-10); // Should throw NegativeQuantityException
        std::cout << "After adding -10 items: " << inv.get_stock() << std::endl;
    } catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }

    std::cout << "Program completed." << std::endl;
    return 0;
}