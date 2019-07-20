#include <iostream>
#include "matrix.h"

int main(){
    std::cout << "Testing..." << std::endl;
    Matrix<int> m(3,3);
    // Matrix<int> m;
    // m.print();
    std::cout << "m = " << m.size().first << " x " << m.size().second << std::endl;
    std::cout << m << std::endl;
    m(1,1) = 1;
    std::cout << "m = " << m.size().first << " x " << m.size().second << std::endl;
    std::cout << m << std::endl;

    Matrix<int> m2;
    m2 = m;
    std::cout << "m2 = " << m.size().first << " x " << m.size().second << std::endl;
    std::cout << m2 << std::endl;

    m = m + m2;

    std::cout << "m + m2 = " << std::endl;
    std::cout << m << std::endl;

    return 0;
}