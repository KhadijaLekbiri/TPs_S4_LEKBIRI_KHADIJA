#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

struct Node {
    int value;                     // Node's value
    Node* left = nullptr;          // Pointer to left child
    Node* right = nullptr;         // Pointer to right child

    Node(int val) : value(val) {}
};

struct BST {
    Node* root = nullptr; // Root node of the tree

    // Add a new node to the tree
    void addNode(int value) {
        root = addNodeRec(root, value);
    }

    Node* addNodeRec(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value)
            node->left = addNodeRec(node->left, value);
        else
            node->right = addNodeRec(node->right, value);

        return node;
    }

    // In-order traversal
    void infixe(Node* node) const {
        if (!node) return;

        infixe(node->left);
        cout << node->value << " ";
        infixe(node->right);
    }

    void infixe() const {
        infixe(root);
        cout << "\n";
    }

    // Search for a value in the tree
    bool find(int value) const {
        Node* current = root;
        while (current) {
            if (current->value == value) {
                cout << "Trouve\n";
                return true;
            }
            current = (value < current->value) ? current->left : current->right;
        }
        cout << "N'existe pas\n";
        return false;
    }

    // Remove a node from the tree
    Node* removeRec(Node* node, int value) {
        if (!node) return nullptr;

        if (value < node->value) {
            node->left = removeRec(node->left, value);
        } else if (value > node->value) {
            node->right = removeRec(node->right, value);
        } else {
            // Node to be deleted found
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Replace with in-order successor
            Node* successor = getMinNode(node->right);
            node->value = successor->value;
            node->right = removeRec(node->right, successor->value);
        }
        return node;
    }

    void remove(int value) {
        root = removeRec(root, value);
    }

    // Find the minimum value node in a subtree
    Node* getMinNode(Node* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Destructor to free the tree's memory
    void clear(Node* node) {
        if (!node) return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    ~BST() {
        clear(root);
    }
};

int main() {
    BST tree;
    std::string line;
    // Add nodes to the tree
    cout << "Insertion des elements : ";
    std::getline(std::cin, line); // Read the entire line
    std::istringstream iss(line); // Process the line for multiple inputs
    int i;
    while (iss >> i) {
        tree.addNode(i);          // Add a node to the tree with the input
    }
    
    // Display the tree (in-order traversal)
    cout << "Parcours infixe : \n";
    tree.infixe();

    // Search for a value
    cout << "\nRecherche de 4 : ";
    tree.find(4);

    // Remove a node and display the tree
    cout << "Suppression de 4\n";
    tree.remove(4);
    
    // Display the tree (in-order traversal) after deleting 4
    cout << "Parcours infixe apres suppression : \n";
    tree.infixe();

    return 0;
}


