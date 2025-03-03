#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Entrer la dimension n: ";
    cin >> n;
    cout << "Entrer la dimension m: ";
    cin >> m;

    // Dynamic allocation of the original matrix
    int** p = new int*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[m];
    }

    // Input elements
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << "Entrer l'element de la ligne " << i << " la colonne " << j << ": ";
            cin >> p[i][j];
        }
    }

    // Print the initial matrix
    cout << "Matrice initiale: " << endl;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    // Dynamic allocation of the transposed matrix
    int** transposed = new int*[m];
    for (int i = 0; i < m; i++) {
        transposed[i] = new int[n];
    }

    // Transpose logic
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            transposed[j][i] = p[i][j];
        }
    }

    // Print the transposed matrix
    cout << "Matrice transposee: " << endl;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory for the original matrix
    for (int i = 0; i < n; i++) {
        delete[] p[i];
    }
    delete[] p;

    // Deallocate memory for the transposed matrix
    for (int i = 0; i < m; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}
