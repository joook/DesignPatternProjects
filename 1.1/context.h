#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <memory>

class FlyBehavior;
class QuackBehavior;

class Duck
{
public:
    Duck(const std::shared_ptr<FlyBehavior> &FlyBehaviorPtr, const std::shared_ptr<QuackBehavior> &QuackBehaviorPtr)
    : m_FlyBehaviorPtr(FlyBehaviorPtr)
    , m_QuackBehaviorPtr(QuackBehaviorPtr)
    {
    }

    virtual ~Duck() = default;

public:
    virtual void display() const = 0;
    void performFly() const;
    void performQuack() const;
    void swim() const;

private:
    std::shared_ptr<FlyBehavior> m_FlyBehaviorPtr;
    std::shared_ptr<QuackBehavior> m_QuackBehaviorPtr;
};

class RedHeadDuck : public Duck
{
public:
    RedHeadDuck();

public:
    virtual void display() const override;
};

class RubberDuck : public Duck
{
public:
    RubberDuck();

public:
    virtual void display() const override;
};

#endif
