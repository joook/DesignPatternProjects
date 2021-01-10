#include "state.h"
#include "context.h"

void SoldOutState::onEnter(GumballMachine* const machine) const
{
}

bool SoldOutState::isValidSwitch(StateId id) const
{
    bool returnValue = true;
    
    if (id == StateId::NO_QUARTER_STATE)
    {
        returnValue = true;
    }
    else
    {
        returnValue = false;
    }
    
    return returnValue;
}

void SoldOutState::onExit(GumballMachine* const machine) const
{
}

void SoldOutState::onInsertQuarterEvent(GumballMachine* const machine) const
{
    machine->notifyInsertQuarterFailed();
}

void SoldOutState::onEjectQuarterEvent(GumballMachine* const machine) const
{
    machine->notifyEjectQuarterFailed();
}

void SoldOutState::onTurnCrankEvent(GumballMachine* const machine) const
{
    machine->notifyTurnCrankFailed();
}

void SoldOutState::onFillEvent(GumballMachine* const machine, std::uint32_t num) const
{
    machine->doFill(num);
    machine->switchToState(StateId::NO_QUARTER_STATE);
}




void NoQuarterState::onEnter(GumballMachine* const machine) const
{
}

bool NoQuarterState::isValidSwitch(StateId id) const
{
    bool returnValue = true;
    
    if (id == StateId::HAS_QUARTER_STATE)
    {
        returnValue = true;
    }
    else
    {
        returnValue = false;
    }
    
    return returnValue;
}

void NoQuarterState::onExit(GumballMachine* const machine) const
{
}

void NoQuarterState::onInsertQuarterEvent(GumballMachine* const machine) const
{
    machine->notifyInsertQuarterDone();
    machine->switchToState(StateId::HAS_QUARTER_STATE);
}

void NoQuarterState::onEjectQuarterEvent(GumballMachine* const machine) const
{
    machine->notifyEjectQuarterFailed();
}

void NoQuarterState::onTurnCrankEvent(GumballMachine* const machine) const
{
    machine->notifyTurnCrankFailed();
}

void NoQuarterState::onFillEvent(GumballMachine* const machine, std::uint32_t num) const
{
    machine->doFill(num);
}




void HasQuarterState::onEnter(GumballMachine* const machine) const
{
}

bool HasQuarterState::isValidSwitch(StateId id) const
{
    bool returnValue = true;
    
    if ((id == StateId::SOLD_OUT_STATE)
        || (id == StateId::NO_QUARTER_STATE))
    {
        returnValue = true;
    }
    else
    {
        returnValue = false;
    }
    
    return returnValue;
}

void HasQuarterState::onExit(GumballMachine* const machine) const
{
}

void HasQuarterState::onInsertQuarterEvent(GumballMachine* const machine) const
{
    machine->notifyInsertQuarterFailed();
}

void HasQuarterState::onEjectQuarterEvent(GumballMachine* const machine) const
{
    machine->notifyEjectQuarterDone();
    machine->switchToState(StateId::NO_QUARTER_STATE);
}

void HasQuarterState::onTurnCrankEvent(GumballMachine* const machine) const
{
    machine->dispenseGumball();
    
    if(machine->checkSoldOut() == true)
    {
        machine->switchToState(StateId::SOLD_OUT_STATE);
    }
    else
    {
        machine->switchToState(StateId::NO_QUARTER_STATE);
    }
}

void HasQuarterState::onFillEvent(GumballMachine* const machine, std::uint32_t num) const
{
    machine->doFill(num);
}


