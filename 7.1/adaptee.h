#ifndef _ADAPTEE_H_
#define _ADAPTEE_H_

class Chicken
{
public:
    virtual void fly() = 0;
    virtual void cluck() = 0;
};

class RedChicken : public Chicken
{
public:
    virtual void fly() override;
    virtual void cluck() override;
};

#endif
