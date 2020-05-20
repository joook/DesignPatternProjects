#ifndef _CONCRETE_CLASS_H_
#define _CONCRETE_CLASS_H_

#include "abstract_class.h"

class Tea : public CaffeineBeverage
{
public:
    virtual void brew() override;
    virtual void addCondiments() override;
};

class Coffee : public CaffeineBeverage
{
public:
    virtual void brew() override;
    virtual void addCondiments() override;
    virtual bool customerWantsCondiments() override;
    char getCustomerInput();
};

#endif
