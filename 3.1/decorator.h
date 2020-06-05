#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <string>
#include "component.h"

class CondimentDecorator : public Beverage //did not consider about copy control
{
public:
    CondimentDecorator(Beverage *BeveragePtr)
    : Beverage(BeveragePtr->getDescription())
    , m_BeveragePtr(BeveragePtr)
    {
    }

public:
    virtual std::string getDescription() const
    {
        return (m_BeveragePtr->getDescription() + ", " + getCondimentDescription());
    }

    virtual double getPrice() const
    {
        return (m_BeveragePtr->getPrice() + getCondimentPrice());
    }

    virtual std::string getCondimentDescription() const = 0;

    virtual double getCondimentPrice() const = 0;

protected:
    Beverage *m_BeveragePtr;
};

class MilkAdded : public CondimentDecorator
{
public:
    MilkAdded(Beverage *BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

public:
    virtual std::string getCondimentDescription() const override
    {
        return "Milk";
    }

    virtual double getCondimentPrice() const override
    {
        return 0.1;
    }
};

class MochaAdded : public CondimentDecorator
{
public:
    MochaAdded(Beverage *BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

public:
    virtual std::string getCondimentDescription() const override
    {
        return "Mocha";
    }

    virtual double getCondimentPrice() const override
    {
        return 0.2;
    }
};

class WhipAdded : public CondimentDecorator
{
public:
    WhipAdded(Beverage *BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

public:
    virtual std::string getCondimentDescription() const override
    {
        return "Whip";
    }

    virtual double getCondimentPrice() const override
    {
        return 0.1;
    }
};

#endif
