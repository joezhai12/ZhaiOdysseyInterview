#include <iostream>
#include "matrix.h"
#include <time.h>
#include <stdlib.h>

// template <class T>
// bool CheckValue(const Matrix<T>& a, const Matrix<T>& b){
//     if(a == b){
//         return true;
//     }
//     return false;
// }

int main(){
    std::srand(time(NULL));

    std::cout << "Testing..." << std::endl;
    // Matrix<int> m(3,3);
    // // Matrix<int> m;
    // // m.print();
    // std::cout << "m = " << m.size().first << " x " << m.size().second << std::endl;
    // std::cout << m << std::endl;
    // m(1,1) = 1;
    // std::cout << "m = " << m.size().first << " x " << m.size().second << std::endl;
    // std::cout << m << std::endl;

    // Matrix<int> m2;
    // m2 = m;
    // std::cout << "m2 = " << m.size().first << " x " << m.size().second << std::endl;
    // std::cout << m2 << std::endl;

    // m = m + m2;

    // std::cout << "m + m2 = " << std::endl;
    // std::cout << m << std::endl;

    // m += m2;
    // std::cout << "m += m2 " << std::endl;
    // std::cout << m << std::endl;

    Matrix<int> m3(3,4);
    Matrix<int> m4(4,2);

    for(int i = 1; i <= m3.size().first; ++i){
        for(int j = 1; j <= m3.size().second; ++j){
            m3(i,j) = std::rand() % 50;
        }
    }

    for(int i = 1; i <= m4.size().first; ++i){
        for(int j = 1; j <= m4.size().second; ++j){
            m4(i,j) = std::rand() % 50;
        }
    }

    std::cout << m3 << std::endl;
    std::cout << m4 << std::endl;
    std::cout << (m3 * m4) << std::endl;

    m3 *= 2;
    std::cout << m3 << std::endl;

    Matrix<int> m5 = (3*m3);

    std::cout << m5 << std::endl;
    std::cout << (m5 - m3) << std::endl;

    m5.Transpose();

    std::cout << m5 << std::endl;

    std::cout << (m3 == m5) << std::endl;
    std::cout << (m3 != m5) << std::endl;

    return 0;
}