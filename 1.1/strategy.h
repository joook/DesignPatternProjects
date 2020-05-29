#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class FlyBehavior
{
public:
    virtual void fly() const = 0;
};

class QuackBehavior
{
public:
    virtual void quack() const = 0;
};

#endif
