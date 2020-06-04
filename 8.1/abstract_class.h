#ifndef _ABSTRACT_CLASS_H_
#define _ABSTRACT_CLASS_H_

class CaffeineBeverage
{
public:
    virtual ~CaffeineBeverage() = default;

public:
    void prepareRecipe()
    {
        boilWater();
        brew();
        pourInCup();
        if(customerWantsCondiments() == true)
        {
            addCondiments();
        }
        else
        {
        }
    }

    void boilWater();
    virtual void brew() = 0;
    void pourInCup();
    virtual void addCondiments() = 0;
    virtual bool customerWantsCondiments() { return true; }
};

#endif
