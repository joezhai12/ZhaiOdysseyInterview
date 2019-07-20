#include "matrix.h"
#ifndef MATRIX_IMPL
#define MATRIX_IMPL

#include <iostream>
#include <vector>

/*
 * Constructor (Empty Matrix)
 */
template <class T>
Matrix<T>::Matrix():
    n(0),
    m(0)
{
    std::cout << "Created Matrix" << std::endl;
}

/*
 * Constructor
 */
template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols):
    n(rows),
    m(cols)
{
    std::cout << "Created Matrix" << std::endl;
    for(int i = 0; i < n; ++i){
        std::vector<T> v;
        for(int j = 0; j < m; ++j){
            v.push_back(0);
        }
        data.push_back(v);
    }
}

/*
 * Destructor
 */
template <class T>
Matrix<T>::~Matrix(){
    std::cout << "Destroying Matrix" << std::endl;
}

/*
 * Copy Constructor
 */
template <class T>
Matrix<T>::Matrix(const Matrix<T>& other):
    n(other.n),
    m(other.m)
{
    for(int i = 0; i < other.size(); ++i){
        std::vector<T> v;
        for(int j = 0; j < other[i].size(); ++j){
            v.push_back(other[i][j]);
        }
        data.push_back(v);
    }
}

/*
 * Operator()
 */
template <class T>
T& Matrix<T>::operator() (unsigned int i, unsigned int j){
    return data[i-1][j-1];
}

/*
 * Print for debug
 */
template <class T>
void Matrix<T>::print(){
    std::cout << "------------" << std::endl;
    for(int i = 0; i < data.size(); ++i){
        for(int j = 0; j < data[i].size(); ++j){
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "------------" << std::endl;
}

#endif