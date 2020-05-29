#ifndef _STORE_H_
#define _STORE_H_

#include <string>
#include <memory>

class Pizza;

class PizzaStore
{
public:
    std::shared_ptr<Pizza> orderPizza(const std::string &Name) const;

protected:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const = 0;
};

class CalifoniaPizzaStore : public PizzaStore
{
protected:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const override;
};

class NYPizzaStore : public PizzaStore
{
protected:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const override;
};

class ChicagoPizzaStore : public PizzaStore
{
protected:
    virtual std::shared_ptr<Pizza> createPizza(const std::string &Name) const override;
};

#endif
