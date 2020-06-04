#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Pizza
{
public:
    virtual ~Pizza() = default;

public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
    std::string getTag() { return m_PizzaInfo; }

protected:
    void setTag(const std::string &Str) { m_PizzaInfo = Str; }

private:
    std::string m_PizzaInfo;
};

class CalifoniaStyleVeggiePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a Califonia veggie pizza."); }
};

class CalifoniaStyleCheesePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a Califonia cheese pizza."); }
};

class CalifoniaStylePepperoniPizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a Califonia pepperoni pizza."); }
};

class NYStyleVeggiePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a NY veggie pizza."); }
};

class NYStyleCheesePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a NY cheese pizza."); }
};

class NYStylePepperoniPizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a NY pepperoni pizza."); }
};

class ChicagoStyleVeggiePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a Chicago veggie pizza."); }
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a Chicago cheese pizza."); }
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a Chicago pepperoni pizza."); }
};

#endif
