#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <string>
#include <list>

class Component
{
public:
    Component(const std::string &Name, double Price)
    : m_Name(Name)
    , m_Price(Price)
    , m_Id(m_SerialId)
    {
        m_SerialId++;
    }

    virtual void add(const std::shared_ptr<Component> &ChildPtr) = 0;
    virtual void remove(const std::shared_ptr<Component> &ChildPtr) = 0;

    std::string getName() const { return m_Name; }
    double getPrice() const { return m_Price; }
    virtual double getTotalPrice() const { return getPrice(); }
    int getId() const { return m_Id; }

private:
    static int m_SerialId;

    std::string m_Name;
    double m_Price;
    int m_Id;
};

class Box : public Component
{
public:
    Box(double Price = 0.5)
    : Component("Package Box", Price)
    , m_ChildPtrListPtr(new std::list<std::shared_ptr<Component>>)
    {
    }

    virtual void add(const std::shared_ptr<Component> &ChildPtr) override;
    virtual void remove(const std::shared_ptr<Component> &ChildPtr) override;

    virtual double getTotalPrice() const override;

private:
    std::shared_ptr<std::list<std::shared_ptr<Component>>> m_ChildPtrListPtr;
};

class Product : public Component
{
public:
    Product(const std::string &Name, double Price)
    : Component(Name, Price)
    {
    }

    virtual void add(const std::shared_ptr<Component> &ChildPtr) override;
    virtual void remove(const std::shared_ptr<Component> &ChildPtr) override;
};

bool isSameId(const std::shared_ptr<Component> &Ptr1, const std::shared_ptr<Component> &Ptr2);

#endif
