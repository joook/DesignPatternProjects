#include "product.h"
#include "factory.h"

using namespace std;

shared_ptr<Pizza> CalifoniaPizzaFactory::createPizza(const string &Name) const
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

shared_ptr<Pizza> NYPizzaFactory::createPizza(const string &Name) const
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

