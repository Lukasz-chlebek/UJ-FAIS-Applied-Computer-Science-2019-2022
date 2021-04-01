#include "Matrix.h"
#include <vector>

Matrix::Matrix() : C(0), R(0){
}

Matrix::Matrix(std::size_t R, std::size_t C):R(R), C(C) {
    tab.resize(R);
    for(size_t i=0; i <R; i++){
        tab[i].resize(C);
    }
}

Matrix::Matrix(const Matrix& source):R(source.R),C(source.C) {
    tab.resize(R);
    for(size_t  i=0; i<R;i++) {
        tab[i].resize(C);
        for (size_t j = 0; j < C; j++) {
            tab[i][j] = source.tab[i][j];
        }
    }
}

void Matrix::setElem(std::size_t i, std::size_t j, double value) {
    if(i>=0 && i <R && j>=0 && j<C)
        tab[i][j] = value;
    else
        std::cout<<"Wrong index"<<std::endl;
}

//wyciaganie elem.
double Matrix::getElem(std::size_t i, std::size_t j) const {
    if(i>=0 && i <R && j>=0 && j<C)
        return tab[i][j];
    else
        std::cout<<"Wrong index"<<std::endl;
    return 0;
}

std::vector<double>& Matrix::operator[](std::size_t i) {
    return tab[i];
}

const std::vector<double>& Matrix::operator[](std::size_t i) const {
    return tab[i];
}

Matrix &Matrix::operator=(const Matrix& source) {
    if(&source != this) {
        R = source.R;
        C = source.C;
        tab.resize(R);
        for (size_t i = 0; i < R; i++) {
            tab[i].resize(C);
            for (size_t j = 0; j < C; j++) {
                tab[i][j] = source.tab[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix&& source) {
    if(&source != this) {
        tab = std::move(source.tab);
        R = source.R;
        C = source.C;
        source.R = 0;
        source.C = 0;
        source.tab.resize(0);
    }
    return *this;
}

Matrix::Matrix(Matrix &&source) {
    if(&source != this) {
        tab = std::move(source.tab);
        R = source.R;
        C = source.C;
        source.R = 0;
        source.C = 0;
        source.tab.resize(0);
    }
}

void Matrix::showElem(std::size_t Row, std::size_t Cols) {
    for(int i=0; i<Row;i++)
    {
        for(int j=0; j<Cols;j++)
        {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}














