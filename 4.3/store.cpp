#include "product.h"
#include "store.h"

using namespace std;

shared_ptr<Pizza> PizzaStore::orderPizza(const string &Name) const
{
    shared_ptr<Pizza> PizzaPtr = createPizza(Name);
    PizzaPtr->prepare();
    PizzaPtr->bake();
    PizzaPtr->cut();
    PizzaPtr->box();

    return PizzaPtr;
}

shared_ptr<Pizza> CalifoniaPizzaStore::createPizza(const string &Name) const
{
    if(Name == "veggie")
    {
        return make_shared<CalifoniaStyleVeggiePizza>();
    }
    else if(Name == "cheese")
    {
        return make_shared<CalifoniaStyleCheesePizza>();
    }
    else
    {
        return make_shared<CalifoniaStylePepperoniPizza>();
    }
}

shared_ptr<Pizza> NYPizzaStore::createPizza(const string &Name) const
{
    if(Name == "veggie")
    {
        return make_shared<NYStyleVeggiePizza>();
    }
    else if(Name == "cheese")
    {
        return make_shared<NYStyleCheesePizza>();
    }
    else
    {
        return make_shared<NYStylePepperoniPizza>();
    }
}

shared_ptr<Pizza> ChicagoPizzaStore::createPizza(const string &Name) const
{
    if(Name == "veggie")
    {
        return make_shared<ChicagoStyleVeggiePizza>();
    }
    else if(Name == "cheese")
    {
        return make_shared<ChicagoStyleCheesePizza>();
    }
    else
    {
        return make_shared<ChicagoStylePepperoniPizza>();
    }
}

