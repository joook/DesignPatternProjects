#include <iostream>
#include <memory>
#include "state.h"
#include "context.h"

using namespace std;

void SoldOutState::insertQuarter(GumballMachine * const MachinePtr) const
{
    cout << "Gumball sold out, can not insert." << endl;
}

void SoldOutState::ejectQuarter(GumballMachine * const MachinePtr) const
{
    cout << "Gumball sold out, can not eject." << endl;
}

void SoldOutState::turnCrank(GumballMachine * const MachinePtr) const
{
    cout << "Gumball sold out, can not turn crank." << endl;
}

void SoldOutState::fill(GumballMachine * const MachinePtr) const
{
    cout << "Gumball machine filled." << endl;
    MachinePtr->setState(NoQuarterStatePtr);
}

void NoQuarterState::insertQuarter(GumballMachine * const MachinePtr) const
{
    cout << "You inserted a quarter." << endl;
    MachinePtr->setState(HasQuarterStatePtr);
}

void NoQuarterState::ejectQuarter(GumballMachine * const MachinePtr) const
{
    cout << "No quarter inserted, can not eject." << endl;
}

void NoQuarterState::turnCrank(GumballMachine * const MachinePtr) const
{
    cout << "No quarter inserted, can not turn crank." << endl;
}

void NoQuarterState::fill(GumballMachine * const MachinePtr) const
{
    cout << "Gumball machine filled." << endl;
}

void HasQuarterState::insertQuarter(GumballMachine * const MachinePtr) const
{
    cout << "Quarter already inserted." << endl;
}

void HasQuarterState::ejectQuarter(GumballMachine * const MachinePtr) const
{
    cout << "Quarter ejected." << endl;
    MachinePtr->setState(NoQuarterStatePtr);
}

void HasQuarterState::turnCrank(GumballMachine * const MachinePtr) const
{
    cout << "Crank turned." << endl;
    MachinePtr->dispenseGumball();
    if(MachinePtr->checkSoldOut() == true)
    {
        MachinePtr->setState(SoldOutStatePtr);
    }
    else
    {
        MachinePtr->setState(NoQuarterStatePtr);
    }
}

void HasQuarterState::fill(GumballMachine * const MachinePtr) const
{
    cout << "Gumball machine filled." << endl;
}

