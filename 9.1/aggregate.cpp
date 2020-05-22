#include "aggregate.h"
#include "iterator.h"
#include "item.h"
#include <iostream>

using namespace std;

shared_ptr<Iterator> DinerMenu::createIterator()
{
    return shared_ptr<Iterator>(new DinerMenuIterator(m_MenuItemList));
}

void DinerMenu::add(const MenuItem &Item)
{
    m_MenuItemList.push_back(Item);
}

shared_ptr<Iterator> BreakfastMenu::createIterator()
{
    return shared_ptr<Iterator>(new BreakfastMenuIterator(m_MenuItemList));
}

void BreakfastMenu::add(const MenuItem &Item)
{
    m_MenuItemList.push_back(Item);
}

void printMenu(const std::shared_ptr<Menu> &MenuPtr)
{
    cout << "[Menu]" << endl;
    shared_ptr<Iterator> ItrPtr = MenuPtr->createIterator();
    while(ItrPtr->hasNext())
    {
        cout << ItrPtr->next()->getFoodName() << endl;
    }
}

