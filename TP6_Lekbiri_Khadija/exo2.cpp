#include <iostream>
#include <vector>
#include <set> // For visited nodes

struct Node {
    int value;                     // Node's value
    std::vector<Node*> neighbors;  // List of neighbors (pointers to other nodes)
};

struct Graph {
    std::vector<Node*> nodes;      // List of all nodes in the graph (dynamic pointers)

    // Add a new node to the graph
    void addNode(int value) {
        Node* newNode = new Node{value, {}}; // Dynamically allocate a new node
        nodes.push_back(newNode);
    }

    // Add a directed edge from node with value `from` to node with value `to`
    void addEdge(int from, int to) {
        Node* fromNode = nullptr;
        Node* toNode = nullptr;

        // Search for nodes with the given values
        for (Node* node : nodes) {
            if (node->value == from) {
                fromNode = node;
            }
            if (node->value == to) {
                toNode = node;
            }
        }

        if (fromNode && toNode) {
            fromNode->neighbors.push_back(toNode);
        } else {
            std::cout << "Error: Invalid nodes for edge (" << from << " -> " << to << ")\n";
        }
    }

    // Perform Depth-First Search (DFS) starting from a specific node
    void depthFirstSearch(int startValue) {
        Node* startNode = nullptr;

        // Find the starting node
        for (Node* node : nodes) {
            if (node->value == startValue) {
                startNode = node;
                break;
            }
        }

        if (!startNode) {
            std::cout << "Error: Starting node not found.\n";
            return;
        }

        // Perform DFS using recursion
        std::set<Node*> visited; // Track visited nodes to avoid infinite loops
        dfs(startNode, visited);
    }

    // DFS implementation (public, no helper function)
    void dfs(Node* node, std::set<Node*>& visited) {
        if (visited.find(node) != visited.end()) {
            return; // Node already visited
        }

        visited.insert(node);          // Mark node as visited
        std::cout << node->value << " "; // Process the node (e.g., print its value)

        for (Node* neighbor : node->neighbors) {
            dfs(neighbor, visited); // Recursively visit neighbors
        }
    }

    // Print the graph structure
    void printGraph() {
        for (Node* node : nodes) {
            std::cout << "Node " << node->value << ": ";
            for (Node* neighbor : node->neighbors) {
                std::cout << neighbor->value << " ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor to free dynamically allocated memory
    ~Graph() {
        for (Node* node : nodes) {
            delete node; // Free each node
        }
    }
};

int main() {
    Graph graph;

    // Add nodes
    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(5, 4);
    graph.addEdge(2, 3);
    graph.addEdge(4, 2);

    // Print graph
    std::cout << "Graph structure:\n";
    graph.printGraph();

    // Perform DFS
    std::cout << "\nParcours en profondeur a partir du sommet 0 :\n";
    graph.depthFirstSearch(0);

    return 0;
}


/*
#include <iostream>
#include <vector>
struct Graph
{   
    std::vector<int> g;
    void add_node(int e){
        g.push_back(e);
    }
    void print(){
        for (int i = 0 ; i < g.size() ; i++){
            std::cout<<"***"<<g[i]<<"***"<<std::endl;
        }
    }
};

using namespace std;

int main(){
    Graph graph_oriente;
    graph_oriente.add_node(2);
    graph_oriente.add_node(0);
    graph_oriente.add_node(9);
    graph_oriente.add_node(44);
    graph_oriente.add_node(6);
    graph_oriente.print();

    return 0;
}


*/