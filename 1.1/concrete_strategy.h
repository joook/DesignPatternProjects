#ifndef _CONCRETE_STRATEGY_H_
#define _CONCRETE_STRATEGY_H_

#include "strategy.h"

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

class Quack : public QuackBehavior
{
public:
    virtual void quack() const override;
};

class Squeak : public QuackBehavior
{
public:
    virtual void quack() const override;
};

class MuteQuack : public QuackBehavior
{
public:
    virtual void quack() const override;
};

#endif
