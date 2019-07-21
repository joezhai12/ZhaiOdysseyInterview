#include <iostream>
#include "matrix.h"
#include <time.h>
#include <stdlib.h>

static int passes = 0;
static int fails = 0;

void Test_Addition(){
    const int ROWS = 3;
    const int COLS = 4;

    Matrix<int> m1(ROWS, COLS);
    Matrix<int> m2(ROWS, COLS);
    
    //populate m1
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            m1(i,j) = (i-1) * ROWS + j;
        }
    }
    // std::cout << m1 << std::endl;
    //populate m2
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            m2(i,j) = -((i-1) * ROWS + j);
        }
    }
    // std::cout << m2 << std::endl;

    Matrix<int> zeros(ROWS, COLS);

    if(zeros == (m1 + m2)){
        ++passes;
    }
    else{
        std::cout << "Addition Test Failed!" << std::endl;
        ++fails;
    }

}

int main(){
    std::srand(time(NULL));
    std::cout << "Testing..." << std::endl;

    Test_Addition();

    std::cout << "Total Tests Passed: " << passes << std::endl;
    std::cout << "Total Tests Failed: " << fails << std::endl;

    return 0;
}