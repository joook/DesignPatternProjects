#include <iostream>
#include <memory>
#include "component.h"
#include "decorator.h"

using namespace std;

void printTag(const Beverage &Bev)
{
    cout << Bev.getDescription();
    cout << "--$" << Bev.getPrice() << endl;
}

int main()
{
    DarkRoast Beverage1;
    MilkAdded Beverage2(&Beverage1);
    WhipAdded Beverage3(&Beverage2);
    Espresso Beverage4;
    MochaAdded Beverage5(&Beverage4);

    printTag(Beverage1);
    printTag(Beverage2);
    printTag(Beverage3);
    printTag(Beverage4);
    printTag(Beverage5);

    return 0;
}
