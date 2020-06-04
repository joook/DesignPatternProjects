#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>
#include <memory>

class Pizza;

class PizzaFactory
{
public:
    virtual ~PizzaFactory() = default;

public:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const = 0;
};

class CalifoniaPizzaFactory : public PizzaFactory
{
public:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const override;
};

class NYPizzaFactory : public PizzaFactory
{
public:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const override;
};

class ChicagoPizzaFactory : public PizzaFactory
{
public:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const override;
};

#endif
