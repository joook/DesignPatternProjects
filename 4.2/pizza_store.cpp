#include "pizza.h"
#include "factory.h"
#include "pizza_store.h"

using namespace std;

shared_ptr<Pizza> PizzaStore::orderPizza(const string &Name) const
{
    shared_ptr<Pizza> PizzaPtr = m_PizzaFactoryPtr->createPizza(Name);
    PizzaPtr->prepare();
    PizzaPtr->bake();
    PizzaPtr->cut();
    PizzaPtr->box();

    return PizzaPtr;
}

