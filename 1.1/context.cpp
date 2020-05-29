#include "context.h"
#include "concrete_strategy.h"
#include <iostream>

using namespace std;

void Duck::performFly() const
{
    m_FlyBehaviorPtr->fly();
}

void Duck::performQuack() const
{
    m_QuackBehaviorPtr->quack();
}

void Duck::swim() const
{
    cout << "I'm swimming..." << endl;
}

RedHeadDuck::RedHeadDuck()
: Duck(make_shared<FlyWithWings>(), make_shared<Quack>())
{
}

void RedHeadDuck::display() const
{
    cout << "I'm a real RedHeadDuck." << endl;
}

RubberDuck::RubberDuck()
: Duck(make_shared<FlyNoWay>(), make_shared<Squeak>())
{
}

void RubberDuck::display() const
{
    cout << "I'm a RubberDuck." << endl;
}

