#include "product.h"
#include "factory.h"

using namespace std;

shared_ptr<Pizza> CalifoniaPizzaFactory::createPizza(const string &Name) const
{
    if(Name == "veggie")
    {
        return make_shared<VeggiePizza>();
    }
    else if(Name == "cheese")
    {
        return make_shared<CheesePizza>();
    }
    else
    {
        return make_shared<PepperoniPizza>();
    }
}
