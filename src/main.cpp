#include <iostream>
#include "matrix.h"

int main(){
    std::cout << "Hello" << std::endl;
    Matrix<int> m(3,3);
    // Matrix<int> m;
    // m.print();
    std::cout << "m =" << std::endl << m << std::endl;
    m(1,1) = 1;
    std::cout << "m =" << std::endl << m << std::endl;

    Matrix<int> m2;
    m2 = m;
    std::cout << "m2 =" << std::endl << m2 << std::endl;

    return 0;
}