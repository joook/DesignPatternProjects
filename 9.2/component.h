#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <string>
#include <list>

class Component
{
public:
    virtual ~Component() = default;

public:
    virtual void add(Component* const ChildPtr) = 0;
    virtual void remove(Component* const ChildPtr) = 0;
    virtual std::string getComponentList() const = 0;
    virtual double getTotalPrice() const = 0;
};

class Box : public Component //did not consider about copy control
{
public:
    Box(double Price = 0.5)
    : m_Name("Package Box")
    , m_Price(Price)
    {
    }

public:
    virtual void add(Component* const ChildPtr) override;
    virtual void remove(Component* const ChildPtr) override;
    virtual std::string getComponentList() const override;
    virtual double getTotalPrice() const override;

    std::string getName() const { return m_Name; }
    double getPrice() const { return m_Price; }

private:
    std::list<Component*> m_ChildPtrList;
    std::string m_Name;
    double m_Price;
};

class Product : public Component
{
public:
    Product(const std::string &Name, double Price)
    : m_Name(Name)
    , m_Price(Price)
    {
    }

public:
    virtual void add(Component* const ChildPtr) override;
    virtual void remove(Component* const ChildPtr) override;
    virtual std::string getComponentList() const override { return getName(); }
    virtual double getTotalPrice() const override { return getPrice(); }

    std::string getName() const { return m_Name; }
    double getPrice() const { return m_Price; }

private:
    std::string m_Name;
    double m_Price;
};

#endif
