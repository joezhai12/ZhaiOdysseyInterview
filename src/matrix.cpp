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
}

/*
 * Constructor
 */
template <class T>
Matrix<T>::Matrix(size_t rows, size_t cols):
    n(rows),
    m(cols)
{
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
}

/*
 * Copy Constructor
 */
template <class T>
Matrix<T>::Matrix(const Matrix<T>& other):
    n(other.n),
    m(other.m)
{
    for(int i = 0; i < other.n; ++i){
        for(int j = 0; j < other.m; ++j){
            this->data[i][j] = other.data[i][j];
        }
    }
}

/*
 * Operator==
 */
template <class T>
bool Matrix<T>::operator== (const Matrix<T>& other){
    if(this->n != other.n || this->m != other.m){
        return false;
    }
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->m; ++j){
            if(this->data[i][j] != other.data[i][j]){
                return false;
            }
        }
    }
    return true;
}

/*
 * Operator!=
 */
template <class T>
bool Matrix<T>::operator!= (const Matrix<T>& other){
    return !(*this == other);
}

/*
 * Operator()
 */
template <class T>
T& Matrix<T>::operator() (size_t i, size_t j){
    return data[i-1][j-1];
}

/*
 * Operator+
 */
template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& other){
    if(this->n != other.n || this->m != other.m){
        throw "Cannot add matrices of different sizes";
    }
    Matrix<T> res(this->n, this->m);
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->m; ++j){
            res.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return res;
}

/*
 * Operator+=
 */
template <class T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T>& other){
    if(this->n != other.n || this->m != other.m){
        throw "Cannot add matrices of different sizes";
    }
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->m; ++j){
            this->data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

/*
 * Operator-
 */
template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix<T>& other){
    if(this->n != other.n || this->m != other.m){
        throw "Cannot subtract matrices of different sizes";
    }
    Matrix<T> res(this->n, this->m);
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->m; ++j){
            res.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return res;
}

/*
 * Operator-=
 */
template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& other){
    if(this->n != other.n || this->m != other.m){
        throw "Cannot add matrices of different sizes";
    }
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->m; ++j){
            this->data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

/*
 * Operator * (Scalar)
 */
template <class T>
Matrix<T> Matrix<T>::operator* (const T& scalar){
    Matrix<T> res(this->n, this->m);
    for(int i = 0; i < res.n; ++i){
        for(int j = 0; j < res.m; ++j){
            res.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return res;
}

/*
 * Operator *= (Scalar)
 */
template <class T>
Matrix<T>& Matrix<T>::operator*= (const T& scalar){
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < this->m; ++j){
            this->data[i][j] *= scalar;
        }
    }
    return (*this);
}

/*
 * Operator * (Matrix)
 */
template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& other){
    if(this->m != other.n){
        throw "Cannot multiply matrices with mismatched inner dimensions";
    }
    Matrix<T> res(this->n, other.m);
    for(int i = 0; i < this->n; ++i){
        for(int j = 0; j < other.m; ++j){
            int el = 0;
            for(int k = 0; k < this->m; ++k){
                el += (this->data[i][k] * other.data[k][j]);
            }
            res.data[i][j] = el;
        }
    }
    return res;
}

/*
 * Tranpose Matrix
 */
template <class T>
Matrix<T>& Matrix<T>::Transpose(){
    Matrix<T> res(this->m, this->n);
    // std::cout << "Debug" << std::endl;
    for(int i = 0; i < this->n; ++i){
        // std::cout << "Debug2" << std::endl;
        for(int j = 0; j < this->m; ++j){
            // std::cout << "Debug3" << std::endl;
            res.data[j][i] = this->data[i][j];
        }
    }
    *this = res;
    return *this;
}


/*
 * Size
 */
template <class T>
inline std::pair<size_t, size_t> Matrix<T>::size(){
    return(std::make_pair(this->n,this->m));
}

/*
 * Rows
 */
template <class T>
inline size_t Matrix<T>::rows(){
    return this->n;
}

/*
 * Columns
 */
template <class T>
inline size_t Matrix<T>::cols(){
    return this->m;
}

#endif