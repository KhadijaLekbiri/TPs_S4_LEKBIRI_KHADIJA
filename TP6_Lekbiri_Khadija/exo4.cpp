#include <iostream>
#include <memory>  // Pour unique_ptr

struct MemoryBlock {
    int size;  // Taille du bloc de mémoire
    std::unique_ptr<int[]> data;  // Pointeur unique pour allouer un tableau d'entiers

    // Constructeur pour allouer un bloc de mémoire
    MemoryBlock(int s) : size(s), data(std::make_unique<int[]>(s)) {
        std::cout << "Bloc de memoire alloue de " << size << " unites.\n";
    }

    // Fusionner deux blocs de mémoire
    void merge(const MemoryBlock& other) {
        size += other.size;
        std::cout << "Fusion des deux blocs : " << size << " unites.\n";
    }

    // libérer explicitement la mémoire
    void freeMemory() {
        data.reset();  // Libère la mémoire allouée au tableau `data`
        std::cout << "Liberation de la memoire. \n";
    }
};

int main() {
    // Allouer un bloc de mémoire
    std::unique_ptr<MemoryBlock> block1 = std::make_unique<MemoryBlock>(100);
    
    // Fusionner des blocs
    MemoryBlock block2(200);
    block1->merge(block2);

    // Libérer explicitement la mémoire allouée pour block1
    block1->freeMemory();

    return 0;
}
