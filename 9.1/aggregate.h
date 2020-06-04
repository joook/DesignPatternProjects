#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_

#include <vector>
#include <set>
#include <memory>

class Iterator;
class MenuItem;

class Menu
{
public:
    virtual ~Menu() = default;

public:
    virtual std::shared_ptr<Iterator> createIterator() = 0;
};

class DinerMenu : public Menu
{
public:
    DinerMenu()
    : m_MenuItemListPtr(new std::vector<MenuItem>())
    {
    }

public:
    virtual std::shared_ptr<Iterator> createIterator() override;
    void add(const MenuItem &Item);

private:
    std::shared_ptr<std::vector<MenuItem>> m_MenuItemListPtr;
};

class BreakfastMenu : public Menu
{
public:
    BreakfastMenu()
    : m_MenuItemListPtr(new std::set<MenuItem>())
    {
    }

public:
    virtual std::shared_ptr<Iterator> createIterator() override;
    void add(const MenuItem &Item);

private:
    std::shared_ptr<std::set<MenuItem>> m_MenuItemListPtr;
};

#endif
