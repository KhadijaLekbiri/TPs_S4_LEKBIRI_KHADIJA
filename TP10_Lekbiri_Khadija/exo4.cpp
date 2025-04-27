
#include <iostream>
#include <array>
#include <type_traits>


using namespace std;
template<typename T, int M, int N>
class Matrix;

template<typename T, int M, int N, int M2, int N2>
class MatrixAdder{
    public:
        static Matrix<T, M, N> add(const Matrix<T, M, N>& m1, const Matrix<T, M2, N2>& m2){
            if constexpr (M == M2 && N == N2) {
                Matrix<T, M, N> result; 
                for (int i = 0; i < M; i++){
                    for (int j = 0; j < N; j++){
                        result.elements.at(i*N+j) = m1.elements.at(i*N+j) + m2.elements.at(i*N+j);   
                    }
                }
                return result;
            } else {
                static_assert(false, "Les dimensions sont incompatibles !!!");
                return Matrix<T, M, N>();
            }
        }
};

template<typename T, int M, int N>

class Matrix {
    public:
        array<T, N*M> elements;

        Matrix(){};

        void set(int i, int j, T e){
            elements.at(i*N+j) = e;
        }

        T get(int i, int j) const{
            return elements.at(i*N+j);
        }

        template<int M2, int N2>
        Matrix<T, M, N> add(const Matrix<T, M2, N2>& matrice) const{ // we can do auto instead of Matrix<T, M, N> if we compile using C++20
            return MatrixAdder<T, M, N, M2, N2>::add(*this, matrice);         
        }
};


int main() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);
    
    auto m3 = m1.add(m2);
    std::cout << m3.get(0, 0) << " " << m3.get(0, 1) << std::endl; // Output: 6 8
    std::cout << m3.get(1, 0) << " " << m3.get(1, 1) << std::endl; // Output: 10 12
    
    Matrix<int, 2, 3> m4; // Incompatible dimensions
    // m1.add(m4); // This would cause a compile-time error (static_assert)
    
    return 0;
}
