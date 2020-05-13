#include <iostream>
#include <memory>
#include "beverage.h"
#include "decorator.h"

using namespace std;

int main()
{
    DarkRoast Beverage1;
    MilkAdded Beverage2(make_shared<DarkRoast>(Beverage1));
    WhipAdded Beverage3(make_shared<MilkAdded>(Beverage2));
    cout << Beverage3.getDescription() << ", $";
    cout << Beverage3.getPrice() << endl;

    return 0;
}
