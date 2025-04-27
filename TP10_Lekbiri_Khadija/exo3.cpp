#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>  // for std::is_same_v

using namespace std;

class PaireBase {
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const = 0;
};

template<typename T, typename U>
class Paire: public PaireBase {
public:
    T v1;
    U v2;

    Paire(T a, U b) : v1(a), v2(b) {}

    void afficher() const override {
        if constexpr (is_same_v<U, bool>) {
            cout << v1 << ", " << (v2 ? "vrai" : "faux") << endl;
        } 
        else {
            cout << v1 << ", " << v2 << endl;
        }
    }
};

template<typename T>
class Paire<T, int>: public PaireBase {
public:
    T v1;
    int v2;

    Paire(T a, int b) : v1(a), v2(b) {}

    void afficher() const override {
        cout << "The second parameter is an integer: " << v2 << endl;
    }
};

int main() {
    std::vector<std::unique_ptr<PaireBase>> paires;
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));

    for (const auto& p : paires) {
        p->afficher();
    }

    return 0;
}
