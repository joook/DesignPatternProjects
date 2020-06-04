#ifndef _STORE_H_
#define _STORE_H_

#include <string>
#include <memory>

class Pizza;
class PizzaFactory;

class PizzaStore
{
public:
    PizzaStore(const std::shared_ptr<PizzaFactory> &PizzaFactoryPtr)
    : m_PizzaFactoryPtr(PizzaFactoryPtr)
    {
    }

public:
    std::shared_ptr<Pizza> orderPizza(const std::string &Name) const;

private:
    std::shared_ptr<PizzaFactory> m_PizzaFactoryPtr;
};

#endif
