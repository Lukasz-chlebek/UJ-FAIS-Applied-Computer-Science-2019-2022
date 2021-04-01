#include <iostream>
#include "Poly.h"

void Test_push(){
    std::cout<<"Test number 1 push():\n";
    Poly<int> poly1;
    poly1.push(5,1);
    std::cout<<poly1<<std::endl;
    poly1.push(6,2);
    std::cout<<poly1<<std::endl;
    poly1.push(2,0);
    std::cout<<poly1<<std::endl;
    poly1.push(2,3);
    std::cout<<poly1<<std::endl;
    poly1.push(7,5);
    std::cout<<poly1<<std::endl;
    poly1.push(6,2);
    std::cout<<poly1<<std::endl;
    if (poly1[5] != 7 || poly1[3] != 2 || poly1[2] != 12 || poly1[1] != 5 || poly1[0] != 2) {
        std::cout << "Error\n";
    } else {
        std::cout << "OK\n";
    }


    std::cout<<"\nTest number 2 push():\n";
    Poly<int> poly2;
    poly2.push(10,0);
    poly2.push(7,1);
    poly2.push(11,2);
    poly2.push(20,3);
    std::cout<<poly2<<std::endl;
    if(poly2[3]!=20 || poly2[2]!=11 || poly2[1]!=7 || poly2[0]!=10){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }

    std::cout<<"_______________________________\n";
}

void Test_add_poly(){
    std::cout<<"Test number 1 add_poly():\n";
    Poly<int> poly1;
    poly1.push(2,3);
    poly1.push(-7,2);
    poly1.push(8,1);
    poly1.push(1,0);
    std::cout<<"Polynominal nr1:\n";
    std::cout<<poly1<<std::endl;
    Poly<int> poly2;
    poly2.push(1,4);
    poly2.push(-1,3);
    poly2.push(3,2);
    poly2.push(-11,1);
    poly2.push(4,0);
    std::cout<<"Polynominal nr2:\n";
    std::cout<<poly2<<std::endl;
    std::cout<<"Polynominal nr1 = nr1 + nr2:\n";
    Poly<int> poly = poly1 + poly2;
    std::cout<<poly<<std::endl;
    if(poly[4]!=1 || poly[3]!=1 || poly[2]!=-4 || poly[1]!=-3 || poly[0]!=5){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }


    std::cout<<"\nTest number 2 add_poly():\n";
    Poly<int> ar1;
    ar1.push(-3,4);
    ar1.push(-3,2);
    ar1.push(-2,0);
    std::cout<<"Polynominal nr1:\n";
    std::cout<<ar1<<std::endl;
    Poly<int>ar2;
    ar2.push(2,3);
    ar2.push(1,1);
    std::cout<<"Polynominal nr2:\n";
    std::cout<<ar2<<std::endl;
    std::cout<<"Polynominal nr1 = nr1 + nr2:\n";
    Poly<int> ar = ar1 + ar2;
    std::cout<<ar<<std::endl;
    if(ar[4]!= -3 || ar[3]!=2 || ar[2]!= -3 || ar[1]!=1 || ar[0]!=-2){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }

    std::cout<<"_______________________________\n";
}

void Test_sub_poly(){
    std::cout<<"Test number 1 sub_poly():\n";
    Poly<int> poly1;
    poly1.push(1,3);
    poly1.push(-3,2);
    poly1.push(5,1);
    poly1.push(9,0);
    std::cout<<"Polynominal nr1:\n";
    std::cout<<poly1<<std::endl;
    Poly<int> poly2;
    poly2.push(-1,3);
    poly2.push(3,2);
    poly2.push(-11,1);
    poly2.push(10,0);
    std::cout<<"Polynominal nr2:\n";
    std::cout<<poly2<<std::endl;
    std::cout<<"Polynominal nr1 = nr1 - nr2\n";
    Poly<int> poly = poly1 - poly2;
    std::cout<<poly<<std::endl;
    if(poly[3]!=2 || poly[2]!=-6 || poly[1]!=16 || poly[0]!=-1){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }


    std::cout<<"\nTest number 2 sub_poly():\n";
    Poly<int> ar1;
    ar1.push(2,4);
    ar1.push(-2,2);
    ar1.push(5,1);
    ar1.push(9,0);
    std::cout<<"Polynominal nr1:\n";
    std::cout<<ar1<<std::endl;
    Poly<int>ar2;
    ar2.push(2,4);
    ar2.push(3,2);
    ar2.push(-11,1);
    ar2.push(10,0);
    std::cout<<"Polynominal nr2:\n";
    std::cout<<ar2<<std::endl;
    std::cout<<"Polynominal nr1 = nr1 - nr2\n";
    Poly<int> ar = ar1 - ar2;
    std::cout<<ar<<std::endl;
    if(ar[4]!= 0 || ar[2] != -5 || ar[1]!= 16 || ar[0]!=-1){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }
    std::cout<<"_______________________________\n";
}

void Test_multiply_poly(){
    std::cout<<"Test number 1 multiply_poly():\n";
    Poly<int> poly1;
    poly1.push(1,3);
    poly1.push(1,2);
    poly1.push(3,0);
    std::cout<<"Polynominal nr1:\n";
    std::cout<<poly1<<std::endl;
    Poly<int> poly2;
    poly2.push(1,2);
    poly2.push(5,1);
    poly2.push(1,0);
    std::cout<<"Polynominal nr2:\n";
    std::cout<<poly2<<std::endl;
    std::cout<<"Polynominal nr3 = nr1 * nr2\n";
    Poly<int> poly3 = poly1* poly2;
    std::cout<<poly3<<std::endl;
    if(poly3[5]!=1 || poly3[4]!=6 || poly3[3]!=6 || poly3[2]!=4 || poly3[1]!=15 || poly3[0]!=3){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }

    std::cout<<"\nTest number 2 multiply_poly():\n";
    Poly<int> ar;
    ar.push(1,3);
    ar.push(1,2);
    ar.push(1,1);
    std::cout<<"Polynominal nr1:\n";
    std::cout<<ar<<std::endl;
    Poly<int> ar1;
    ar1.push(4,2);
    ar1.push(1,1);
    ar1.push(1,0);
    std::cout<<"Polynominal nr2:\n";
    std::cout<<ar1<<std::endl;
    std::cout<<"Polynominal nr3 = nr1 * nr2\n";
    Poly<int> ar2 = ar * ar1;
    std::cout<<ar2<<std::endl;
    if(ar2[5]!=4 || ar2[4]!=5 || ar2[3]!=6 || ar2[2]!=2 || ar2[1]!=1){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }
    std::cout<<"_______________________________\n";
}

void Test_horner_algorithm(){
    std::cout<<"Test  number 1 horner():\n";
    Poly<int> poly1;
    poly1.push(-1,3);
    poly1.push(7,2);
    poly1.push(-1,1);
    std::cout<<"Algorithm is finding value of polynominal for x = -3\n";
    std::cout<<"Polynominal:\n";
    std::cout<<poly1<<std::endl;
    std::cout << "Result value is: " << poly1.horner(-3) << "\n";
    if(poly1.horner(-3)!= 93){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }

    std::cout<<"\nTest  number 2 horner():\n";
    Poly<int> poly2;
    poly2.push(-10,6);
    poly2.push(7,5);
    poly2.push(-3,4);
    poly2.push(2,3);
    poly2.push(-9,2);
    poly2.push(20,1);
    poly2.push(-100,0);
    std::cout<<"Algorithm is finding value of polynominal for x = 2\n";
    std::cout<<"Polynominal:\n";
    std::cout<<poly2<<std::endl;
    std::cout << "Result value is : " << poly2.horner(2) << "\n";
    if(poly2.horner(2)!= -544){
        std::cout<<"Error\n";
    } else{
        std::cout<<"OK\n";
    }
    std::cout<<"_______________________________\n";
}

