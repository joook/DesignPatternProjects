#ifndef _DUCK_H_
#define _DUCK_H_

#include <memory>

class FlyBehavior;
class QuackBehavior;

class Duck
{
public:
    virtual void display() const = 0;
    void performFly() const;
    void performQuack() const;
    void swim() const;

protected:
    Duck(const std::shared_ptr<FlyBehavior> &FlyBehaviorPtr, const std::shared_ptr<QuackBehavior> &QuackBehaviorPtr)
    : m_FlyBehaviorPtr(FlyBehaviorPtr)
    , m_QuackBehaviorPtr(QuackBehaviorPtr)
    {
    }

    void setFlyBehavior(const std::shared_ptr<FlyBehavior> &FlyBehaviorPtr)
    {
        m_FlyBehaviorPtr = FlyBehaviorPtr;
    }

    void setQuackBehavior(const std::shared_ptr<QuackBehavior> &QuackBehaviorPtr)
    {
        m_QuackBehaviorPtr = QuackBehaviorPtr;
    }

private:
    std::shared_ptr<FlyBehavior> m_FlyBehaviorPtr;
    std::shared_ptr<QuackBehavior> m_QuackBehaviorPtr;
};

class GreenHeadDuck : public Duck
{
public:
    GreenHeadDuck();
    virtual void display() const override;
};

class RubberDuck : public Duck
{
public:
    RubberDuck();
    virtual void display() const override;
};

#endif
