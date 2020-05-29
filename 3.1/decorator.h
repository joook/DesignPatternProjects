#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <memory>
#include <string>
#include "component.h"

class CondimentDecorator : public Beverage
{
public:
    CondimentDecorator(const std::shared_ptr<Beverage> &BeveragePtr)
    : Beverage(BeveragePtr->getDescription())
    , m_BeveragePtr(BeveragePtr)
    {
    }

    virtual std::string getDescription() const
    {
        return m_BeveragePtr->getDescription();
    }

    virtual double getPrice() const
    {
        return m_BeveragePtr->getPrice();
    }

protected:
    std::shared_ptr<Beverage> m_BeveragePtr;
};

class NoCondimentAdded : public CondimentDecorator
{
public:
    NoCondimentAdded(const std::shared_ptr<Beverage> &BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

    virtual std::string getDescription() const override
    {
        return (m_BeveragePtr->getDescription() + ", No Condiment");
    }

    virtual double getPrice() const override
    {
        return (m_BeveragePtr->getPrice() + 0.0);
    }
};

class MilkAdded : public CondimentDecorator
{
public:
    MilkAdded(const std::shared_ptr<Beverage> &BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

    virtual std::string getDescription() const override
    {
        return (m_BeveragePtr->getDescription() + ", Milk");
    }

    virtual double getPrice() const override
    {
        return (m_BeveragePtr->getPrice() + 0.1);
    }
};

class MochaAdded : public CondimentDecorator
{
public:
    MochaAdded(const std::shared_ptr<Beverage> &BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

    virtual std::string getDescription() const override
    {
        return (m_BeveragePtr->getDescription() + ", Mocha");
    }

    virtual double getPrice() const override
    {
        return (m_BeveragePtr->getPrice() + 0.2);
    }
};

class SoyAdded : public CondimentDecorator
{
public:
    SoyAdded(const std::shared_ptr<Beverage> &BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

    virtual std::string getDescription() const override
    {
        return (m_BeveragePtr->getDescription() + ", Soy");
    }

    virtual double getPrice() const override
    {
        return (m_BeveragePtr->getPrice() + 0.15);
    }
};

class WhipAdded : public CondimentDecorator
{
public:
    WhipAdded(const std::shared_ptr<Beverage> &BeveragePtr)
    : CondimentDecorator(BeveragePtr)
    {
    }

    virtual std::string getDescription() const override
    {
        return (m_BeveragePtr->getDescription() + ", Whip");
    }

    virtual double getPrice() const override
    {
        return (m_BeveragePtr->getPrice() + 0.1);
    }
};

#endif
