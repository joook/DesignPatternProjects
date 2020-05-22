#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <memory>
#include <vector>
#include <list>

class MenuItem;

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual std::shared_ptr<MenuItem> next() = 0;
};

class DinerMenuIterator : public Iterator
{
public:
    DinerMenuIterator(const std::vector<MenuItem> &MenuItemList)
    : m_MenuItemList(MenuItemList)
    , m_Pos(m_MenuItemList.begin())
    {
    }

    virtual bool hasNext() override;
    virtual std::shared_ptr<MenuItem> next() override;

private:
    std::vector<MenuItem> m_MenuItemList;
    std::vector<MenuItem>::iterator m_Pos;
};

class BreakfastMenuIterator : public Iterator
{
public:
    BreakfastMenuIterator(const std::list<MenuItem> &MenuItemList)
    : m_MenuItemList(MenuItemList)
    , m_Pos(m_MenuItemList.begin())
    {
    }

    virtual bool hasNext() override;
    virtual std::shared_ptr<MenuItem> next() override;

private:
    std::list<MenuItem> m_MenuItemList;
    std::list<MenuItem>::iterator m_Pos;
};

#endif
