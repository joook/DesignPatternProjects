#include <iostream>
#include "product.h"
#include "factory.h"
#include "store.h"

using namespace std;

void printPizzaTag(const shared_ptr<Pizza> &PizzaPtr)
{
    cout << PizzaPtr->getTag() << endl;
}

int main()
{
    PizzaStore Store(make_shared<CalifoniaPizzaFactory>());
    auto PizzaPtr1 = Store.orderPizza("cheese");
    auto PizzaPtr2 = Store.orderPizza("veggie");
    printPizzaTag(PizzaPtr1);
    printPizzaTag(PizzaPtr2);

    return 0;
}

