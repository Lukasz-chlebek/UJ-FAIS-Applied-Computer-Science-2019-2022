#include <iostream>
#include "Complex.h"

Complex::Complex() : rez_(0), imz_(0){}

Complex::Complex(double rez, double imz) : rez_(rez), imz_(imz){}

double Complex::getReal() { return rez_; }

double Complex::getImag() { return imz_; }

void Complex::setReal(double rez) { rez_=rez; }

void Complex::setImag(double imz) { imz_=imz; }

Complex Complex::add(Complex v1) {
    return Complex(rez_+v1.rez_,imz_+v1.imz_);
}

Complex Complex::sub(Complex v1) {
    return Complex(rez_-v1.rez_,imz_-v1.imz_);
}

Complex Complex::mul(Complex v1) {
    return Complex(rez_*v1.rez_-imz_*v1.imz_,rez_*v1.imz_-v1.rez_*imz_);
}

Complex Complex::div(Complex v1) {
    return Complex((rez_*v1.rez_+imz_*v1.imz_)/(v1.rez_*v1.rez_+v1.imz_*v1.imz_),(imz_*v1.rez_+rez_*v1.imz_)/(v1.rez_*v1.rez_+v1.imz_*v1.imz_));
}

Complex Complex::operator+(const Complex &v1) const {
    return Complex(rez_+v1.rez_,imz_+v1.imz_);
}

Complex Complex::operator-(const Complex &v1) const {
    return Complex(rez_-v1.rez_,imz_-v1.imz_);
}

void Complex::print() {
    if(imz_<0){ std::cout<<rez_<<imz_<<"i"<<std::endl; }
    else { std::cout<<rez_<<"+"<<imz_<<"i"<<std::endl; }
}

Complex Complex::operator/(const Complex &v1) const {
    return Complex((rez_*v1.rez_+imz_*v1.imz_)/(v1.rez_*v1.rez_+v1.imz_*v1.imz_),(imz_*v1.rez_+rez_*v1.imz_)/(v1.rez_*v1.rez_+v1.imz_*v1.imz_));
}

Complex Complex::operator*(const Complex &v1) const {
    return Complex(rez_*v1.rez_-imz_*v1.imz_,rez_*v1.imz_-v1.rez_*imz_);
}

Complex Complex::operator=(const Complex &v1){
    rez_=v1.rez_;
    imz_=v1.imz_;
    return Complex();
}
