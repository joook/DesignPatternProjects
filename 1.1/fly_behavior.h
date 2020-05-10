#ifndef _FLY_BEHAVIOR_H_
#define _FLY_BEHAVIOR_H_

class FlyBehavior
{
public:
    virtual void fly() const = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    virtual void fly() const override;
};

class FlyNoWay : public FlyBehavior
{
public:
    virtual void fly() const override;
};

#endif
