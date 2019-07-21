#include <iostream>
#include "matrix.h"
#include <time.h>
#include <stdlib.h>

static int passes = 0;
static int fails = 0;

void Test_Addition(const size_t ROWS, const size_t COLS){
    Matrix<int> m1(ROWS, COLS);
    Matrix<int> m2(ROWS, COLS);
    
    //populate m1
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            m1(i,j) = (i-1) * COLS + j;
        }
    }
    // std::cout << m1 << std::endl;
    //populate m2
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            m2(i,j) = -((i-1) * COLS + j);
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

void Test_Subtraction(const size_t ROWS, const size_t COLS){
    Matrix<long> m1(ROWS, COLS);
    Matrix<long> m2(ROWS, COLS);
    
    //populate m1
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            m1(i,j) = (i-1) * COLS + j;
        }
    }
    // std::cout << m1 << std::endl;
    //populate m2
    m2 = m1;
    // std::cout << m2 << std::endl;

    Matrix<long> zeros(ROWS, COLS);

    if(zeros == (m1 - m2)){
        ++passes;
    }
    else{
        std::cout << "Subtraction Test Failed!" << std::endl;
        ++fails;
    }
}

void Test_Matrix_Multiplication(){
    const int N = 3;
    const int M = 4;
    const int P = 2;

    Matrix<float> m1(N,M);
    Matrix<float> m2(M,P);
    Matrix<float> m3(N,P);
    // populate m1
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            m1(i,j) = (i-1) * M + j + 0.5;
        }
    }
    // std::cout << m1 << std::endl;
    // populate m2
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= P; ++j){
            m2(i,j) = (i-1) * P + j + 0.5;
        }
    }
    // std::cout << m2 << std::endl;

    m3(1,1) = 64.0;
    m3(1,2) = 76.0;
    m3(2,1) = 136.0;
    m3(2,2) = 164.0;
    m3(3,1) = 208.0;
    m3(3,2) = 252.0;

    // std::cout << m3 << std::endl;
    // std::cout << (m1 * m2) << std::endl;

    if(m3 == (m1 * m2)){
        ++passes;
    }
    else{
        std::cout << "Matrix Multiplication Test Failed!" << std::endl;
        ++fails;
    }
}

void Test_Scalar_Multiplication(const size_t ROWS, const size_t COLS){
    Matrix<long> m1(ROWS, COLS);
    Matrix<long> ans(ROWS, COLS);
    const long SCALAR = 6;
    
    //populate m1
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            m1(i,j) = (i-1) * COLS + j;
        }
    }
    //populate ans
    for(int i = 1; i <= ROWS; ++i){
        for(int j = 1; j <= COLS; ++j){
            ans(i,j) = ((i-1) * COLS + j) * SCALAR;
        }
    }

    if((SCALAR * m1 == ans) && (m1 * SCALAR == ans)){
        ++passes;
    }
    else{
        std::cout << "Scalar Multiplication Test Failed!" << std::endl;
        ++fails;
    }
}

int main(){
    std::cout << "Testing..." << std::endl;

    Test_Addition(3,4);
    Test_Addition(0,0);
    Test_Subtraction(7,6);
    Test_Subtraction(0,0);
    Test_Matrix_Multiplication();
    Test_Scalar_Multiplication(4,5);
    Test_Scalar_Multiplication(0,0);

    std::cout << "Total Tests Passed: " << passes << std::endl;
    std::cout << "Total Tests Failed: " << fails << std::endl;

    return 0;
}