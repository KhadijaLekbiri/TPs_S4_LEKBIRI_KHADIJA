#include <iostream> // Includes the standard input/output

#ifndef EXO
#define EXO 1
#endif


#if EXO == 1
const float PI = 3.14; // Define the constante PI as a float 
int main(){
    // Verify if the macro DEBUG is defined or not
    #ifdef DEBUG 
        std::cout << "La macro DEBUG est definie." << std::endl;
    #else
        std::cout << "La macro DEBUG n'est pas definie." << std::endl;
    #endif
    // Display the value of PI
    std::cout << "La valeur de PI est: " << PI << std::endl;
    return 0;
}
#elif EXO == 2
int main(int argc, char* argv[]) { // The main function takes arguments
    // Displaying the given arguments using for loop
    for (int i=0; i<argc; i++){
        std::cout <<"l'argument "<<i <<" :"<< argv[i] <<std::endl;
    }
    return 0;
}
#elif EXO == 3
// Create a new namespace
namespace person {
    int age = 18;
    int weight = 60;
} // namespace person

int main() {
    /*Display the variable 'age' declared in a specific namespace
    and use 'std::cout' without 'using namespace std'*/
        std::cout <<"I am " <<person::age<<std::endl; 
    /*Using 'cout' and 'endl' with 'using namespace std'*/
        using namespace std;
        cout << "This is a c++ code." << endl;
    return 0;
}
#elif EXO == 4
int main() {
    int entier;
    float decimal;
    // The user enter the integer and the float
    std::cout << "Entrez un entier: ";
    std::cin >> entier;
    std::cout << "Entrez un nombre decimal: ";
    std::cin >> decimal;
    // Display the given input
    std::cout << "Valeurs saisies: " <<entier<<" et "<<decimal<<std::endl;
    return 0;
}
#else
#error "Veuillez definir EXO a 1,2,3 ou 4 (exemple: -DEXO=1, -DEXO=2, etc.)"
#endif

