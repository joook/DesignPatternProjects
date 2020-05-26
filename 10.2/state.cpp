#include <iostream>
#include <memory>
#include "state.h"
#include "context.h"

using namespace std;

void SoldOutState::insertQuarter() const
{
    cout << "Gumball sold out, can not insert." << endl;
}

void SoldOutState::ejectQuarter() const
{
    cout << "Gumball sold out, can not eject." << endl;
}

void SoldOutState::turnCrank() const
{
    cout << "Gumball sold out, can not turn crank." << endl;
}

void SoldOutState::fill() const
{
    cout << "Gumball machine filled." << endl;
    m_MachinePtr->setState(m_MachinePtr->getNoQuarterStatePtr());
}

void NoQuarterState::insertQuarter() const
{
    cout << "You inserted a quarter." << endl;
    m_MachinePtr->setState(m_MachinePtr->getHasQuarterStatePtr());
}

void NoQuarterState::ejectQuarter() const
{
    cout << "No quarter inserted, can not eject." << endl;
}

void NoQuarterState::turnCrank() const
{
    cout << "No quarter inserted, can not turn crank." << endl;
}

void NoQuarterState::fill() const
{
    cout << "Gumball machine filled." << endl;
}

void HasQuarterState::insertQuarter() const
{
    cout << "Quarter already inserted." << endl;
}

void HasQuarterState::ejectQuarter() const
{
    cout << "Quarter ejected." << endl;
    m_MachinePtr->setState(m_MachinePtr->getNoQuarterStatePtr());
}

void HasQuarterState::turnCrank() const
{
    cout << "Crank turned." << endl;
    m_MachinePtr->dispenseGumball();
    if(m_MachinePtr->checkSoldOut() == true)
    {
        m_MachinePtr->setState(m_MachinePtr->getSoldOutStatePtr());
    }
    else
    {
        m_MachinePtr->setState(m_MachinePtr->getNoQuarterStatePtr());
    }
}

void HasQuarterState::fill() const
{
    cout << "Gumball machine filled." << endl;
}

