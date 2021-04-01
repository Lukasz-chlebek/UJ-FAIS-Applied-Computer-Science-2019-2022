#include <iostream>
#include <cstdint>
#include <vector>

class Matrix {
    int C;
    int R;
    std::vector<std::vector<double>> tab;
public:

    Matrix();
    Matrix(std::size_t Row, std::size_t Col);
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
    Matrix(Matrix&&);
    Matrix& operator=(Matrix&&);


    void setElem(std::size_t i, std::size_t j, double value);
    double getElem(std::size_t i , std::size_t j) const;
    void showElem(std::size_t Row, std::size_t Cols);

    std::vector<double>& operator[](std::size_t i);
    const std::vector<double>& operator[](std::size_t i) const;
    friend std::ostream &operator<<(std::ostream &stream, const Matrix &v1);
    friend std::istream &operator>>(std::istream &stream, Matrix &v1);
};


