#include <iostream>
#include "setArr.h"
int main()
{
    std::cout << "Set tests\n***********************\n";

    setArr X = setArr();
    std::cout << X.isInSet(10) <<"\n";
    X.insert(10);
    std::cout << X.isInSet(10) << "\n";

    X.insert(50); X.insert(11); X.insert(11); X.insert(2); X.insert(3);
    std::cout << "set size  "<<X.getSize();

    std::cout << "\nSet X    ";
    X.printSet();

    setArr Y = setArr();
    Y.insert(1); Y.insert(2); Y.insert(5);
    std::cout << "\nSet Y    ";
    Y.printSet();
    std::cout<<"\n";

    std::cout << "Sum of sets\n";
    setArr Z = X + Y;
    std::cout << "Set Z    ";
    Z.printSet();
    std::cout<<"\n";

    std::cout << "Intersection of sets\n";
    setArr Z1 = X * Y;
    std::cout << "Set Z1    ";
    Z1.printSet();
    std::cout<<"\n";

    std::cout << "Difference of sets\n";
    setArr Z2 = X - Y;
    std::cout << "Set Z2    ";
    Z2.printSet();

    std::cout << "\n\nAdding number out of range test\n";
    X.insert(111);


    std::cout << "\n\n\nComparison test/concluding sets\n";
    setArr C = setArr();
    C.insert(1); C.insert(2); C.insert(4);
    setArr D = setArr();
    D.insert(1); D.insert(2); D.insert(4); D.insert(7);


    std::cout << (bool)(C <= D)<<"\n";
    std::cout << (bool)(D <= C)<<"\n";
    std::cout << (bool)(C == C) << "\n";
}
