#include <iostream>
#include <memory>
#include "component.h"
#include "decorator.h"

using namespace std;

void printTag(const Beverage &Bev)
{
    cout << Bev.getDescription() << ", $";
    cout << Bev.getPrice() << endl;
}

int main()
{
    DarkRoast Beverage1;
    MilkAdded Beverage2(make_shared<DarkRoast>(Beverage1));
    WhipAdded Beverage3(make_shared<MilkAdded>(Beverage2));
    HouseBlend Beverage4;
    SoyAdded Beverage5(make_shared<HouseBlend>(Beverage4));

    printTag(Beverage1);
    printTag(Beverage2);
    printTag(Beverage3);
    printTag(Beverage4);
    printTag(Beverage5);

    return 0;
}
