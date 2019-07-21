#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template <class T>
class Matrix{
public:
    // constructors
    Matrix(); // creates empty matrix object
    Matrix(size_t rows, size_t cols); // creates zero matrix of size rows x cols

    // destructor
    ~Matrix();

    // copy constructor
    Matrix(const Matrix<T>& other);

    // operator()
    // used to access element (i,j) of matrix
    // NOTE: return indexed by 1 (REQ)
    T& operator() (size_t i, size_t j);

    // addition
    Matrix<T> operator+ (const Matrix<T>& other);
    Matrix<T>& operator+= (const Matrix<T>& other);
    Matrix<T> operator - (const Matrix<T>& other);
    Matrix<T>& operator-= (const Matrix<T>& other);

    // scalar multiplication
    Matrix<T> operator* (const T& scalar);
    Matrix<T>& operator*= (const T& scalar);
    // allow commutative scalar mult.
    friend Matrix<T> operator* (const T& scalar, Matrix<T>& mat){
        return (mat * scalar);
    };

    // matrix multiplication
    Matrix<T> operator* (const Matrix<T>& other);

    // transpose matrix
    Matrix<T>& Transpose();

    friend std::ostream& operator<< (std::ostream& os, const Matrix& mat){
        for(int i = 0; i < mat.n; ++i){
            for(int j = 0; j < mat.m; ++j){
                os << mat.data[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }

    std::pair<size_t, size_t> size();

private:
    // n x m Matrix
    size_t n;
    size_t m;
    std::vector< std::vector<T> > data;

};
#include "matrix.cpp"

#endif
