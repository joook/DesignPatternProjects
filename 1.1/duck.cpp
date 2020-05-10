#include "duck.h"
#include "fly_behavior.h"
#include "quack_behavior.h"
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

GreenHeadDuck::GreenHeadDuck()
: Duck(make_shared<FlyWithWings>(), make_shared<Quack>())
{
}

void GreenHeadDuck::display() const
{
    cout << "I'm a real GreenHeadDuck." << endl;
}

RubberDuck::RubberDuck()
: Duck(make_shared<FlyNoWay>(), make_shared<Squeak>())
{
}

void RubberDuck::display() const
{
    cout << "I'm a RubberDuck." << endl;
}

