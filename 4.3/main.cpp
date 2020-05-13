#include <iostream>
#include "pizza.h"
#include "pizza_store.h"

using namespace std;

void printPizzaTag(const shared_ptr<Pizza> &PizzaPtr)
{
    cout << PizzaPtr->getTag() << endl;
}

int main()
{
    CalifoniaPizzaStore Store1;
    auto PizzaPtr1 = Store1.orderPizza("cheese");
    auto PizzaPtr2 = Store1.orderPizza("veggie");
    printPizzaTag(PizzaPtr1);
    printPizzaTag(PizzaPtr2);

    NYPizzaStore Store2;
    auto PizzaPtr3 = Store2.orderPizza("cheese");
    auto PizzaPtr4 = Store2.orderPizza("veggie");
    printPizzaTag(PizzaPtr3);
    printPizzaTag(PizzaPtr4);

    return 0;
}

