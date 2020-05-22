#include "aggregate.h"
#include "iterator.h"
#include "item.h"
#include <iostream>

using namespace std;

shared_ptr<Iterator> DinerMenu::createIterator()
{
    return shared_ptr<Iterator>(new DinerMenuIterator(m_MenuItemListPtr));
}

void DinerMenu::add(const MenuItem &Item)
{
    m_MenuItemListPtr->push_back(Item);
}

shared_ptr<Iterator> BreakfastMenu::createIterator()
{
    return shared_ptr<Iterator>(new BreakfastMenuIterator(m_MenuItemListPtr));
}

void BreakfastMenu::add(const MenuItem &Item)
{
    m_MenuItemListPtr->insert(Item);
}

