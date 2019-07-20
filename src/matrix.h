#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template <class T>
class Matrix{
public:
    // constructors
    Matrix(); // creates empty matrix object
    Matrix(unsigned int rows, unsigned int cols); // creates zero matrix of size rows x cols

    // destructor
    ~Matrix();

    // copy constructor
    Matrix(const Matrix<T>&);

    // operator()
    // NOTE: return indexed by 1 (REQ)
    T& operator() (unsigned int i, unsigned int j);

    // addition
    // Matrix operator + (const Matrix&);
    // Matrix operator - (const Matrix&);

    // // multiplication
    // Matrix operator * (const Matrix&);

    friend std::ostream& operator<< (std::ostream& os, Matrix& mat){
        for(int i = 0; i < mat.n; ++i){
            for(int j = 0; j < mat.m; ++j){
                os << mat.data[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }
private:
    // n x m Matrix
    unsigned int n;
    unsigned int m;
    std::vector< std::vector<T> > data;

};
#include "matrix.cpp"

#endif
