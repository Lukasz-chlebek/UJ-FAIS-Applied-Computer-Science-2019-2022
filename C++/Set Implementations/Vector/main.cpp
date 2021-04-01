#include <iostream>
#include <vector>
#include "set.h"

int main()
{
    std::cout << std::boolalpha;

    set X = set();
    X.insert(2);
    X.insert(4);
    X.insert(5);
    X.insert(9);
    X.insert(6);
    X.insert(9);
    X.insert(7);
    X.printSet();
    std::cout << "set size: " << X.getSize()<<"\n";

    X.withdraw(4);
    X.printSet();
    std::cout << "set size: " << X.getSize()<<"\n";

    set Y = set();
    Y.insert(1); Y.insert(2); Y.insert(8); Y.insert(1000);

    std::cout << "\nSet X ";
    X.printSet();
    std::cout << "\nSet Y ";
    Y.printSet();
    std::cout<<"\n";

    set Z = X + Y;
    std::cout << "Sum X+Y   ";
    Z.printSet();
    std::cout<<"\n";

    set Z1 = X * Y;
    std::cout << "Product X * Y   ";
    Z1.printSet();
    std::cout<<"\n";

    set Z2 = X - Y;
    std::cout << "difference X - Y   ";
    Z2.printSet();

    std::cout << "\n\n\nTest comparsion/ concluding sets\n";
    set C = set();
    C.insert(1); C.insert(2); C.insert(4);
    set D = set();
    D.insert(1); D.insert(2); D.insert(4); D.insert(7);

    std::cout << (bool)(C <= D) << "\n";
    std::cout << (bool)(D <= C) << "\n";
    std::cout << (bool)(C == C) << "\n";
}
