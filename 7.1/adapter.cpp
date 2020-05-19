#include "adapter.h"
#include "adaptee.h"

void ChickenAdapter::fly()
{
    if(m_ChickenPtr)
    {
        m_ChickenPtr->fly();
    }
    else
    {
    }
}

void ChickenAdapter::quack()
{
    if(m_ChickenPtr)
    {
        m_ChickenPtr->cluck();
    }
    else
    {
    }
}
