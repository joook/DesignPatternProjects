#include <iostream>
#include <stdexcept>
#include <functional>
#include "component.h"

using namespace std;

int Component::m_SerialId = 0;

void Box::add(const std::shared_ptr<Component> &ChildPtr)
{
    m_ChildPtrListPtr->push_back(ChildPtr);
}

void Box::remove(const std::shared_ptr<Component> &ChildPtr)
{
    m_ChildPtrListPtr->remove_if(bind(isSameId, placeholders::_1, ChildPtr));
}

double Box::getTotalPrice() const
{
    double Price = getPrice();
    for(auto Itr = m_ChildPtrListPtr->begin()
    ; Itr != m_ChildPtrListPtr->cend(); Itr++)
    {
        Price += (*Itr)->getTotalPrice();
    }
    return Price;
}

void Product::add(const std::shared_ptr<Component> &ChildPtr)
{
    throw runtime_error("Leaf node does not have child.");
}

void Product::remove(const std::shared_ptr<Component> &ChildPtr)
{
    throw runtime_error("Leaf node does not have child.");
}

bool isSameId(const std::shared_ptr<Component> &Ptr1, const std::shared_ptr<Component> &Ptr2)
{
    if(Ptr1->getId() == Ptr2->getId())
    {
        return true;
    }
    else
    {
        return false;
    }
}

