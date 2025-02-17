#include <iostream> // Includes the standard input/output
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm> // for std::sort
#include <utility> // for std::pair
using namespace std;

#ifndef EXO
#define EXO 1
#endif


#if EXO == 1
    int main(){
        int C[5] = {10,20,30,40,50};
        int sum = 0;
        cout<<"Elements : ";
        for (int i = 0; i < 5; i++)
        {
            cout<<C[i]<<" "; 
            sum += C[i]; //la somme des elements de la liste
        }
        cout<<"\nSomme : "<<sum;
        return 0;
    }
#elif EXO == 2
    int main(){
        int C[3][3] = {{1,2,3},{4,5,6},{7,8,9}};//we create a matrix
        int sum = 0;
        cout<<"Matrice : ";
        // we iterate through each element and we display the matrix row by row
        for (int i = 0; i < 3; i++){
            cout<<"\n";
            for (int j = 0; j < 3; j++){
                cout<<C[i][j]<<" ";
                if (i==j){
                    sum += C[i][j]; // calcul of the sum of the diagole
                }}
            }

        cout<<"\nSomme diagonle : "<<sum;
        return 0;
    }
#elif EXO == 3
    int main() {
        std::array<int, 5> tab = {1, 2, 3, 4, 5};
        int j = tab.size();
        int temp = 0; //  variable temporaire
        cout<<"Original : ";// display the original array
        for (int i = 0; i < tab.size(); i++)
        {   
            cout<<tab[i]<<" ";
        }
        for (int i = 0; i < tab.size()/2; i++)
        {   
            // swaping the elements tab[i] and tab[j-i-1]
            temp = tab[i];
            tab[i] = tab[j-i-1];
            tab[j-i-1] = temp;
        }
        cout<<"Inverse : "; // display the updated array
        for (int i = 0; i < tab.size(); i++)
        {   
            cout<<tab[i]<<" ";
        }
        return 0;
    }
#elif EXO == 4
    int main() {

        std::vector<int> test_;
        int num;
        cout<<"Entrer des nombres entiers: ";
        while (true)
        {
            cin>>num;
            if (num == -1){ //the input stop when we enter -1
                break;
            }
            test_.push_back(num);
        }
        cout<<"Original : ";// display the original vector
        for (int i=0; i<test_.size(); i++){
            cout<<test_[i]<<" ";
            test_[i] *= 2; 
        }
        cout<<"\nDouble : "; // display the double of each element of the vector
        for (int i=0; i<test_.size(); i++){cout<<test_[i]<<" ";}
        
        return 0;
    }
#elif EXO == 5
    int main() {

        std::list<int> test_;
        int num = 3;
        int val;
        while (num)
        {
            cout<<"Entrer un nombre entier au debut: "; // add to the front
            cin>>val;
            test_.push_front(val);
            cout<<"Entrer un nombre entier a la fin: ";// add to the back
            cin>>val;
            test_.push_back(val);
            num--;
        }

        cout<<"\nApres insertion : "; // final result
        for (int value : test_){cout<<value<<" ";}
        
        return 0;
    }
#elif EXO == 6
    int main() {

        std::set<int> test_;
        int num;
        int val;
        // creating the set
        cout<<"Entrer le nombre des elements a inserer: ";
        cin>>num;
        cout<<"Entrer les nombres entiers a inserer: ";
        while (num){
            cin>>val;
            test_.insert(val);
            num--;
        }
        // adding repeated value
        cout<<"Entrer un nombre qui existe deja: ";
        cin>>val;
        cout<<"\nOriginal :";
        for (int value : test_){cout<<value<<" ";}
        test_.insert(val);
        cout<<"\nApres insertion de "<<val<<" : "; // the set does not allow repitition
        for (int value : test_){cout<<value<<" ";}
        
        return 0;
    }
#elif EXO == 7
    int main() {
        std::map<string,int> mp;
        int num;
        char nom[20];
        int note;
        cout<<"Entrer le nombre des etudiants a inserer: ";
        cin>>num;
        while (num){
            cout<<"Entrer le nom de l'etudiant: ";
            cin>>nom;
            cout<<"Entrer sa note: ";
            cin>>note;
            mp[nom] = note;
            num--;
        }
        /* we can not use a for loop since the elements are
         ordered autommatically inside the map */
        cout<<"John : "<<mp["John"]<<endl;
        cout<<"Alice : "<<mp["Alice"]<<endl;
        cout<<"Bob : "<<mp["Bob"]<<endl;
        return 0;
    }
#elif EXO == 8
int main() {
    std::unordered_map<string,int> mp;
    string word;
    cout<<"Entrer une phrase (entrer 'fin' pour finir): ";
    while(cin >> word){
        if (word != "fin"){// the input stop when the user enter the word "fin"
            if (mp.find(word)==mp.end()){// verify if the map contains the word as a key or not 
                mp[word] = 1;
            }
            else{
                mp[word] += 1;
            }}
        else{
            break;
        }}
    for (auto paire : mp){
        cout<<paire.first<<" : "<<paire.second<<endl;
    }
    return 0;
}
#elif EXO == 9
    int main() {

        std::vector<int> vec;
        int num;
        cout<<"Entrer des nombres entiers (entrer -1 pour arreter): ";
        while (true)
        {
            cin>>num;
            if (num == -1){
                break;
            }
            vec.push_back(num);
        }
        cout<<"Original : "; //before sorting
        for (int i=0; i<vec.size(); i++){cout<<vec[i]<<" ";}
        sort(vec.begin(),vec.end()); // we sort the vector 
        cout<<"\nTrie : ";//after sorting
        for (int i=0; i<vec.size(); i++){cout<<vec[i]<<" ";}    
        return 0;
    }
#elif EXO == 10
    int main() {
        std::set<int> test = {100, 4, 200, 1, 3, 2};

        // Find the longest sequence of consecutive numbers
        vector<int> longestSeq, currentSeq;
        int prev = *test.begin();
        currentSeq.push_back(prev);

        for (auto it = next(test.begin()); it != test.end(); ++it) {
            if (*it == prev + 1) {
                currentSeq.push_back(*it);
            } else {
                if (currentSeq.size() > longestSeq.size()) {
                    longestSeq = currentSeq;
                }
                currentSeq = {*it};  // Start a new sequence
            }
            prev = *it;
        }

        // If the last sequence is the longest, update longestSeq
        if (currentSeq.size() > longestSeq.size()) {
            longestSeq = currentSeq;
        }

        // Print the longest sequence
        std::cout << "\nPlus longue sequence : ";
        std::cout << longestSeq.size() << " (";
        for (int num : longestSeq) {
            if (num != *longestSeq.end()){
                std::cout<< ", "<<num;
            }
            else{
                std::cout<<num;
            }
        }
        std::cout <<") "<< endl;

        return 0;
    }

#elif EXO == 11
    // Déclaration des structures globales pour le cache
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
    std::list<std::pair<int, int>> cacheList;
    int capacity;

    // Fonction pour insérer ou mettre à jour un élément dans le cache
    void put(int key, int value) {
        // Si la clé existe déjà, on la met à jour et on la déplace en tête de liste
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.erase(cacheMap[key]); // Supprimer l'élément existant de la liste
        }

        // Si la capacité est atteinte, supprimer l'élément le moins récemment utilisé
        if (cacheList.size() == capacity) {
            // Supprimer le dernier élément de la liste (le moins récemment utilisé)
            cacheMap.erase(cacheList.back().first);
            cacheList.pop_back();
        }

        // Ajouter le nouvel élément en tête de la liste
        cacheList.push_front({key, value});
        // Mettre à jour la table de hachage avec l'itérateur vers le nouvel élément
        cacheMap[key] = cacheList.begin();
    }

    // Fonction pour obtenir un élément du cache
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Si la clé n'existe pas, retourner -1
        }

        // Déplacer l'élément en tête de la liste pour le marquer comme récemment utilisé
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);

        return cacheMap[key]->second; // Retourner la valeur associée à la clé
    }

    // Fonction pour afficher le contenu actuel du cache
    void display() {
        std::cout<<"Etat du cache : ";
        for (auto& p : cacheList) {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
    }

    int main() {
        // Initialiser le cache avec une capacité de 2
        capacity = 2;

        // Ajouter (1, 10) et (2, 20) au cache
        put(1, 10);
        put(2, 20);
        display();

        // Accéder à la clé 1 (ce qui la rend récemment utilisée)
        std::cout << "Acces a la cle 1 : " << get(1) << std::endl;
        display();

        // Ajouter (3, 30), ce qui devrait supprimer (2, 20)
        put(3, 30);
        std::cout << "Ajout de (3, 30), supression de (2, 20)"<<std::endl;
        display();

        return 0;
    }

#else
#error "Veuillez definir EXO a 1,2,3 ou 4 (exemple: -DEXO=1, -DEXO=2, etc.)"
#endif

