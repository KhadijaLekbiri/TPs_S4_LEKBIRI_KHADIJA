#include <iostream>
#include <list>
#include <sstream>
#include <unordered_map>
#include <memory>

using namespace std;

struct LRUCache {
    int capacity; // Capacité maximale du cache
    std::list<int> keys; // Liste chaînée pour maintenir l'ordre d'accès des clés
    std::unordered_map<int, std::shared_ptr<int>> cache; // Associe une clé à sa valeur
    std::unordered_map<int, std::weak_ptr<int>> weak_refs; // Évite les cycles

    // Constructeur pour initialiser la capacité
    LRUCache(int cap) : capacity(cap) {}

    // Fonction pour accéder ou insérer une clé
    void access(int key) {
        if (cache.find(key) != cache.end()) {
            // Si la clé existe déjà, on la déplace en tête
            keys.remove(key);
            keys.push_front(key);
        } else {
            // Si la clé n'existe pas, on vérifie la capacité
            if (cache.size() == capacity) {
                evict(); // Supprime le moins récemment utilisé
            }
            keys.push_front(key);
            cache[key] = std::make_shared<int>(key); // Ajoute la clé avec un `shared_ptr`
        }
    }

    // Fonction pour évincer la clé la moins récemment utilisée
    void evict() {
        int old_key = keys.back(); // La clé à la fin de la liste est la moins récente
        keys.pop_back(); // Supprime la clé de la liste
        cache.erase(old_key); // Supprime la clé du cache
    }

    // Fonction pour afficher le contenu actuel du cache
    void display() const {

        std::cout << "Cache actuel : \n";
        for (int key : keys) {
            std::cout << key << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    LRUCache cache(4); // Capacité maximale = 4
    int i;
    std::string line;
    // Accès aux clés
    cout << "Acces aux cles : ";
    std::getline(std::cin, line); // Read the entire line
    std::istringstream iss(line); // Process the line for multiple inputs
    while (iss >> i) {
        cache.access(i);          // Access the cache with the input
    }
    
    // Affiche l'état actuel du cache
    cache.display();

    // Ajout de la clé 5 (éviction de la clé 2)
    cout<<"Acces a la cle 5 -> Eviction de la cle 2 \n";
    cache.access(5);

    // Affiche l'état du cache après l'éviction
    cache.display();

    return 0;
}
