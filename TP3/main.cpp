#include <iostream> // Includes the standard input/output
#include <limits>
using namespace std;

#ifndef EXO
#define EXO 1
#endif


#if EXO == 1
    int main(){
        int tab[10] = {0,1,2,3,4,5,6,7,8,9};
        cout<<"Taille totale du tableau : "<<sizeof(tab)<<" octet(s)"<<endl;
        cout<<"Taille d'un element : "<<sizeof(tab[0])<<" octet(s)"<<endl;
        cout<<"Nombre d'elements : "<<sizeof(tab)/sizeof(tab[0])<<endl;
        return 0;
    }
#elif EXO == 2
    int main(){
        const int psr = 250;
        const int plr = 350;
        const float ptax = 6;
        const int days = 30;
        int s,l,cost,tax; // creating variables 
        cout<<"Number of small rooms: ";
        cin>>s;
        cout<<"Number of large rooms: ";
        cin>>l;
        // Price of each room in dh
        cout<<"Price per small room: "<<psr<<" dh"<<endl;
        cout<<"Price per large room: "<<plr<<" dh"<<endl;
        cost = s*psr + l*plr;
        cout<<"Cost: "<<cost<<" dh"<<endl;
        tax = cost*ptax/100;
        cout<<"Tax: "<<tax<<" dh"<<endl;
        // Total amount
        cout<<"==================================="<<endl;
        cout<<"Total estimate: "<<tax + cost<<" dh"<<endl;
        cout<<"This estimate is valid for "<<days<<" days"<<endl;
        return 0;
    }
#elif EXO == 3
    constexpr int factoriel(int n){
        if (n <= 1){
            return 1;}
        return factoriel(n - 1) * n;}

    int main(){
        constexpr int res = factoriel(5);
        // is the result given by the function != 120 , an error occur 
        static_assert(res == 120,"Error: La factorielle de 5 doit être 120");
        //otherwise the answer is correcte
        std::cout<<"La factorielle de 5 est correcte: "<<res<<std::endl;
        return 0;
    }
#elif EXO == 4
    int valeur = 100;// variable globale

    int main(){
        int valeur = 50;// variable locale
        cout<<"Valeur locale: "<<valeur<<endl;
        cout<<"Valeur globale: "<<::valeur<<endl; // '::' nous permet d'accéder a la variable globale
        return 0;
    }
#elif EXO == 5
    int main(){
        //manipulation des différentes constantes
        const int nbr_mois = 12;
        constexpr float rayon = 7.0;
        #define pi 3.14159
        cout<<"Nombre de mois dans une annee :"<<nbr_mois<<endl;
        cout<<"Rayon du cercle : "<<rayon<<endl;
        cout<<"Aire du cercle : "<<rayon*rayon*pi<<endl;
        return 0;
    }
#elif EXO == 6
    int safeMultiply(int a, int b){
        int l = numeric_limits<int>::max(); // l is the limit of int
        if (b!=0 && a>l/b){
            cout<<"La multiplication depasse la limite! "<<endl;
            return -1; //if the product exceed the limit, the function return -1 
        } 
        return a*b;
    }

    int main(){
        int a = 3000000;
        int b = 1000;
        int result = safeMultiply(a, b);
        cout<<result<<endl;
        return 0;
    }
#else
#error "Veuillez definir EXO a 1,2,3 ou 4 (exemple: -DEXO=1, -DEXO=2, etc.)"
#endif

