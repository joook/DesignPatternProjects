#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Pizza
{
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

class VeggiePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a VeggiePizza."); }
};

class CheesePizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a CheesePizza."); }
};

class PepperoniPizza : public Pizza
{
public:
    virtual void prepare() override {}
    virtual void bake() override {}
    virtual void cut() override {}
    virtual void box() override { setTag("It's a PepperoniPizza."); }
};

#endif
