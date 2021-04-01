#include "Complex.h"
#include <iostream>


Complex operator+( double liczba, Complex v1 ){
    return {liczba+v1.rez_, v1.imz_};
}

Complex operator+( Complex v1, double liczba ){
    return {liczba+v1.rez_, v1.imz_};
}
Complex operator-( double liczba, Complex v1 ){
    return {liczba-v1.rez_, -v1.imz_};
}
Complex operator-( Complex v1, double liczba ){
    return {v1.rez_-liczba, v1.imz_};
}
Complex operator*( double liczba, Complex v1 ){
    return {liczba*v1.rez_, liczba*v1.imz_};
}
Complex operator*( Complex v1, double liczba ){
    return {liczba*v1.rez_, liczba*v1.imz_};
}

Complex operator/(double liczba, Complex v1) {

    return Complex ((liczba*v1.rez_)/(v1.rez_*v1.rez_+v1.imz_*v1.imz_),(liczba*-v1.imz_)/(v1.rez_*v1.rez_+v1.imz_*v1.imz_));
}
Complex operator/( Complex v1, double liczba ){
    return {liczba/v1.rez_, liczba/v1.imz_};
}

std::ostream &operator<<(std::ostream &stream, const Complex &v1){
    if(v1.imz_==0 && v1.rez_==0)
        stream <<"0";
    else {
        if (v1.imz_ > 0) {
            stream << v1.rez_ << "+" << v1.imz_ << "i";
        }
        else {
            stream << v1.rez_ << v1.imz_ << "i";
        }
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Complex &v1){
    double &rez=v1.rez_;
        stream>>rez;
    double &imz=v1.imz_;
        stream>> imz;
    return stream;
}


