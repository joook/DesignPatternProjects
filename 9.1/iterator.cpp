#include "iterator.h"
#include "item.h"

using namespace std;

bool DinerMenuIterator::hasNext()
{
    if(m_Pos != m_MenuItemList.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

shared_ptr<MenuItem> DinerMenuIterator::next()
{
    shared_ptr<MenuItem> TempPtr = make_shared<MenuItem>(*m_Pos);
    m_Pos++;
    return TempPtr;
}

bool BreakfastMenuIterator::hasNext()
{
    if(m_Pos != m_MenuItemList.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

shared_ptr<MenuItem> BreakfastMenuIterator::next()
{
    shared_ptr<MenuItem> TempPtr = make_shared<MenuItem>(*m_Pos);
    m_Pos++;
    return TempPtr;
}

