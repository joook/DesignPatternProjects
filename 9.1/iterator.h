#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <memory>
#include <vector>
#include <set>

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
    DinerMenuIterator(const std::shared_ptr<std::vector<MenuItem>> &MenuItemListPtr)
    : m_MenuItemListPtr(MenuItemListPtr)
    , m_Pos(m_MenuItemListPtr->begin())
    {
    }

    virtual bool hasNext() override;
    virtual std::shared_ptr<MenuItem> next() override;

private:
    std::shared_ptr<std::vector<MenuItem>> m_MenuItemListPtr;
    std::vector<MenuItem>::iterator m_Pos;
};

class BreakfastMenuIterator : public Iterator
{
public:
    BreakfastMenuIterator(const std::shared_ptr<std::set<MenuItem>> &MenuItemListPtr)
    : m_MenuItemListPtr(MenuItemListPtr)
    , m_Pos(m_MenuItemListPtr->begin())
    {
    }

    virtual bool hasNext() override;
    virtual std::shared_ptr<MenuItem> next() override;

private:
    std::shared_ptr<std::set<MenuItem>> m_MenuItemListPtr;
    std::set<MenuItem>::iterator m_Pos;
};

#endif
