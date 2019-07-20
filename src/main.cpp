#include <iostream>
#include "matrix.h"

int main(){
    std::cout << "Hello" << std::endl;
    Matrix<int> m(3,3);
    // Matrix<int> m;
    m.print();
    m[1][1] = 1;
    m.print();
    return 0;
}