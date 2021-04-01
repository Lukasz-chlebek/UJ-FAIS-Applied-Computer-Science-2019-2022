class Complex {
private:
    double rez_;
    double imz_;
public:

    Complex();
    Complex( double rez, double imz );
    double getReal();
    double getImag();
    void setReal( double rez );
    void setImag( double imz );
    Complex add( Complex v1 );
    Complex sub( Complex v1 );
    Complex div( Complex v1 );
    Complex mul( Complex v1 );
    Complex operator+( const Complex& v1 )const;
    Complex operator-( const Complex& v1 )const;
    Complex operator/( const Complex& v1 )const;
    Complex operator*( const Complex& v1 )const;
    Complex operator=( const Complex& v1 );
    void print();
    friend Complex operator+( double liczba, Complex v1 );
    friend Complex operator+( Complex v1, double liczba );
    friend Complex operator-( double liczba, Complex v1 );
    friend Complex operator-( Complex v1, double liczba );
    friend Complex operator*( double liczba, Complex v1 );
    friend Complex operator*( Complex v1, double liczba );
    friend Complex operator/( double liczba, Complex v1 );
    friend Complex operator/( Complex v1, double liczba );
    friend std::ostream &operator<<(std::ostream &stream, const Complex &v1);
    friend std::istream &operator>>(std::istream &stream, Complex &v1);
};



