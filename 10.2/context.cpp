#include <iostream>
#include <memory>
#include "context.h"
#include "state.h"

using namespace std;

GumballMachine::GumballMachine()
: m_SoldOutStatePtr(std::make_shared<SoldOutState>(this))
, m_NoQuarterStatePtr(std::make_shared<NoQuarterState>(this))
, m_HasQuarterStatePtr(std::make_shared<HasQuarterState>(this))
, m_StatePtr(getSoldOutStatePtr())
, m_GumballCount(0)
{
}

void GumballMachine::insertQuarter()
{
    m_StatePtr->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    m_StatePtr->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    m_StatePtr->turnCrank();
}

void GumballMachine::fill(unsigned int Num)
{
    m_GumballCount += Num;
    if(m_GumballCount > 0)
    {
        m_StatePtr->fill();
    }
    else
    {
    }
}

void GumballMachine::dispenseGumball()
{
    cout << "A gumball rolled out!" << endl;
    m_GumballCount--;
}

