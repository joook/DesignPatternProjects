#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class FlyBehavior
{
public:
    virtual ~FlyBehavior() = default;

public:
    virtual void fly() const = 0;
};

class QuackBehavior
{
public:
    virtual ~QuackBehavior() = default;

public:
    virtual void quack() const = 0;
};

#endif
