#include "component.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<Component> OuterBox(new Box(1.00));
    shared_ptr<Component> AccessoryBox(new Box);
    shared_ptr<Component> iPhone(new Product("iPhone 4s", 5000.00));
    shared_ptr<Component> Charger(new Product("iPhone Charger", 50.00));
    shared_ptr<Component> EarPhones(new Product("iPhone EarPhones", 100.00));

    OuterBox->add(iPhone);
    OuterBox->add(Charger);
    OuterBox->remove(Charger);
    OuterBox->add(AccessoryBox);
    AccessoryBox->add(Charger);
    AccessoryBox->add(EarPhones);

    cout << "Total price is: " << OuterBox->getTotalPrice() << endl;

    return 0;
}

