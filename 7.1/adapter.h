#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "target.h"

class Chicken;

class ChickenAdapter : public Duck //did not consider about copy control
{
public:
    ChickenAdapter(Chicken * const ChickenPtr)
    : Duck()
    , m_ChickenPtr(ChickenPtr)
    {
    }

    virtual void fly() override;
    virtual void quack() override;

private:
    Chicken *m_ChickenPtr;
};

#endif
