#include "component.h"
#include <iostream>

using namespace std;

int main()
{
    Box OuterBox(1.00);
    Box AccessoryBox;
    Product iPhone("iPhone 4s", 5000.00);
    Product Charger("iPhone Charger", 50.00);
    Product EarPhones("iPhone EarPhones", 100.00);

    OuterBox.add(&iPhone);
    OuterBox.add(&Charger);
    OuterBox.remove(&Charger);
    OuterBox.add(&AccessoryBox);
    AccessoryBox.add(&Charger);
    AccessoryBox.add(&EarPhones);

    cout << "Product list: " << OuterBox.getComponentList() << endl;
    cout << "Total price is: " << OuterBox.getTotalPrice() << endl;

    return 0;
}

