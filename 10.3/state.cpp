#include "state.h"
#include "context.h"
#include "event.h"

void SoldOutState::onEnter() const
{
}

void SoldOutState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == EventId::INSERT_QUARTER)
        {
            getContext()->notifyInsertQuarterFailed();
        }
        else if (event->m_Id == EventId::EJECT_QUARTER)
        {
            getContext()->notifyEjectQuarterFailed();
        }
        else if (event->m_Id == EventId::TURN_CRANK)
        {
            getContext()->notifyTurnCrankFailed();
        }
        else if (event->m_Id == EventId::FILL)
        {
            std::uint32_t* data = (std::uint32_t*)(event->m_Data);
            getContext()->doFill(*data);
            
            getContext()->switchToState(StateId::NO_QUARTER_STATE);
        }
        else
        {
            // error id
        }
    }
    else
    {
    }
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




void NoQuarterState::onEnter() const
{
}

void NoQuarterState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == EventId::INSERT_QUARTER)
        {
            getContext()->notifyInsertQuarterDone();
            
            getContext()->switchToState(StateId::HAS_QUARTER_STATE);
        }
        else if (event->m_Id == EventId::EJECT_QUARTER)
        {
            getContext()->notifyEjectQuarterFailed();
        }
        else if (event->m_Id == EventId::TURN_CRANK)
        {
            getContext()->notifyTurnCrankFailed();
        }
        else if (event->m_Id == EventId::FILL)
        {
            std::uint32_t* data = (std::uint32_t*)(event->m_Data);
            getContext()->doFill(*data);
        }
        else
        {
            // error id
        }
    }
    else
    {
    }
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




void HasQuarterState::onEnter() const
{
}

void HasQuarterState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == EventId::INSERT_QUARTER)
        {
            getContext()->notifyInsertQuarterFailed();
        }
        else if (event->m_Id == EventId::EJECT_QUARTER)
        {
            getContext()->notifyEjectQuarterDone();
            
            getContext()->switchToState(StateId::NO_QUARTER_STATE);
        }
        else if (event->m_Id == EventId::TURN_CRANK)
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
        else if (event->m_Id == EventId::FILL)
        {
            std::uint32_t* data = (std::uint32_t*)(event->m_Data);
            getContext()->doFill(*data);
        }
        else
        {
            // error id
        }
    }
    else
    {
    }
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

