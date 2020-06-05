#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>

class Beverage
{
public:
    Beverage(const std::string &Str = "Unknown Beverage") : m_Description(Str) {}
    virtual ~Beverage() = default;

public:
    virtual std::string getDescription() const { return m_Description; }
    virtual double getPrice() const = 0;

private:
    std::string m_Description;
};

class DarkRoast : public Beverage
{
public:
    DarkRoast() : Beverage("Dark Roast Coffee") {}

public:
    virtual double getPrice() const override { return 0.99; }
};

class Decaf : public Beverage
{
public:
    Decaf() : Beverage("Decaf Coffee") {}

public:
    virtual double getPrice() const override { return 1.05; }
};

class Espresso : public Beverage
{
public:
    Espresso() : Beverage("Espresso Coffee") {}

public:
    virtual double getPrice() const override { return 1.99; }
};

#endif
