#ifndef _QUACK_BEHAVIOR_H_
#define _QUACK_BEHAVIOR_H_

class QuackBehavior
{
public:
    virtual void quack() const = 0;
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
