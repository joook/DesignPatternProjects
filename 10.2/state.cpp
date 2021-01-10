#include "state.h"
#include "context.h"

void SoldOutState::onEnter() const
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

void SoldOutState::onExit() const
{
}

void SoldOutState::onInsertQuarterEvent() const
{
    getContext()->notifyInsertQuarterFailed();
}

void SoldOutState::onEjectQuarterEvent() const
{
    getContext()->notifyEjectQuarterFailed();
}

void SoldOutState::onTurnCrankEvent() const
{
    getContext()->notifyTurnCrankFailed();
}

void SoldOutState::onFillEvent(std::uint32_t num) const
{
    getContext()->doFill(num);
    getContext()->switchToState(StateId::NO_QUARTER_STATE);
}




void NoQuarterState::onEnter() const
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

void NoQuarterState::onExit() const
{
}

void NoQuarterState::onInsertQuarterEvent() const
{
    getContext()->notifyInsertQuarterDone();
    getContext()->switchToState(StateId::HAS_QUARTER_STATE);
}

void NoQuarterState::onEjectQuarterEvent() const
{
    getContext()->notifyEjectQuarterFailed();
}

void NoQuarterState::onTurnCrankEvent() const
{
    getContext()->notifyTurnCrankFailed();
}

void NoQuarterState::onFillEvent(std::uint32_t num) const
{
    getContext()->doFill(num);
}




void HasQuarterState::onEnter() const
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

void HasQuarterState::onExit() const
{
}

void HasQuarterState::onInsertQuarterEvent() const
{
    getContext()->notifyInsertQuarterFailed();
}

void HasQuarterState::onEjectQuarterEvent() const
{
    getContext()->notifyEjectQuarterDone();
    getContext()->switchToState(StateId::NO_QUARTER_STATE);
}

void HasQuarterState::onTurnCrankEvent() const
{
    getContext()->dispenseGumball();
    
    if(getContext()->checkSoldOut() == true)
    {
        getContext()->switchToState(StateId::SOLD_OUT_STATE);
    }
    else
    {
        getContext()->switchToState(StateId::NO_QUARTER_STATE);
    }
}

void HasQuarterState::onFillEvent(std::uint32_t num) const
{
    getContext()->doFill(num);
}


