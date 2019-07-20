#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

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

    // operator[]
    // NOTE: return indexed by 1
    std::vector<T>& operator[] (unsigned int i);

    // assignment
    // = overload


    // addition
    // Matrix operator + (const Matrix&);
    // Matrix operator - (const Matrix&);

    // // multiplication
    // Matrix operator * (const Matrix&);

    void print();
    
private:
    // n x m Matrix
    const unsigned int n;
    const unsigned int m;
    std::vector< std::vector<T> > data;

};
#include "matrix.cpp"

#endif
