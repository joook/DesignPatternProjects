#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_

#include <vector>
#include <list>
#include <memory>

class Iterator;
class MenuItem;

class Menu
{
public:
    virtual std::shared_ptr<Iterator> createIterator() = 0;
};

class DinerMenu : public Menu
{
public:
    virtual std::shared_ptr<Iterator> createIterator() override;
    void add(const MenuItem &Item);

private:
    std::vector<MenuItem> m_MenuItemList;
};

void printMenu(const std::shared_ptr<Menu> &MenuPtr);

class BreakfastMenu : public Menu
{
public:
    virtual std::shared_ptr<Iterator> createIterator() override;
    void add(const MenuItem &Item);

private:
    std::list<MenuItem> m_MenuItemList;
};

void printMenu(const std::shared_ptr<Menu> &MenuPtr);

#endif
