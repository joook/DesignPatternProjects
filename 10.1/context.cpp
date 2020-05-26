#include <iostream>
#include <memory>
#include "context.h"
#include "state.h"

using namespace std;

GumballMachine::GumballMachine()
: m_StatePtr(SoldOutStatePtr)
, m_GumballCount(0)
{
}

void GumballMachine::insertQuarter()
{
    m_StatePtr->insertQuarter(this);
}

void GumballMachine::ejectQuarter()
{
    m_StatePtr->ejectQuarter(this);
}

void GumballMachine::turnCrank()
{
    m_StatePtr->turnCrank(this);
}

void GumballMachine::fill(unsigned int Num)
{
    m_GumballCount += Num;
    if(m_GumballCount > 0)
    {
        m_StatePtr->fill(this);
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

