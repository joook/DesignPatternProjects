#include <iostream>
#include <stdexcept>
#include "component.h"

using namespace std;

void Box::add(Component* const ChildPtr)
{
    m_ChildPtrList.push_back(ChildPtr);
}

void Box::remove(Component* const ChildPtr)
{
    m_ChildPtrList.remove(ChildPtr);
}

string Box::getComponentList() const
{
    string List = getName();
    for(auto Itr = m_ChildPtrList.begin()
    ; Itr != m_ChildPtrList.cend(); Itr++)
    {
        List += ", ";
        List += (*Itr)->getComponentList();
    }
    return List;
}

double Box::getTotalPrice() const
{
    double Price = getPrice();
    for(auto Itr = m_ChildPtrList.begin()
    ; Itr != m_ChildPtrList.cend(); Itr++)
    {
        Price += (*Itr)->getTotalPrice();
    }
    return Price;
}

void Product::add(Component* const ChildPtr)
{
    throw runtime_error("Leaf node does not have child.");
}

void Product::remove(Component* const ChildPtr)
{
    throw runtime_error("Leaf node does not have child.");
}


