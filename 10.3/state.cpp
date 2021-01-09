#include <iostream>
#include <memory>
#include "state.h"
#include "context.h"
#include "event.h"

void SoldOutState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == EventId::INSERT_QUARTER)
        {
            std::cout << m_Machine->getMachineName() << ": Gumball sold out, can not insert." << std::endl;
        }
        else if (event->m_Id == EventId::EJECT_QUARTER)
        {
            std::cout << m_Machine->getMachineName() << ": Gumball sold out, can not eject." << std::endl;
        }
        else if (event->m_Id == EventId::TURN_CRANK)
        {
            std::cout << m_Machine->getMachineName() << ": Gumball sold out, can not turn crank." << std::endl;
        }
        else if (event->m_Id == EventId::FILL)
        {
            std::uint32_t* data = (std::uint32_t*)(event->m_Data);
            m_Machine->doFill(*data);
            std::cout << m_Machine->getMachineName() << ": Gumball machine filled with " << *data;
            std::cout << ((*data > 1) ? " gumballs." : " gumball.") << std::endl;
            
            m_Machine->switchToNoQuarterState();
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

void SoldOutState::onEnter() const
{
}

void SoldOutState::onExit() const
{
}

void NoQuarterState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == EventId::INSERT_QUARTER)
        {
            std::cout << m_Machine->getMachineName() << ": You inserted a quarter." << std::endl;
            
            m_Machine->switchToHasQuarterState();
        }
        else if (event->m_Id == EventId::EJECT_QUARTER)
        {
            std::cout << m_Machine->getMachineName() << ": No quarter inserted, can not eject." << std::endl;
        }
        else if (event->m_Id == EventId::TURN_CRANK)
        {
            std::cout << m_Machine->getMachineName() << ": No quarter inserted, can not turn crank." << std::endl;
        }
        else if (event->m_Id == EventId::FILL)
        {
            std::uint32_t* data = (std::uint32_t*)(event->m_Data);
            m_Machine->doFill(*data);
            std::cout << m_Machine->getMachineName() << ": Gumball machine filled with " << *data;
            std::cout << ((*data > 1) ? " gumballs." : " gumball.") << std::endl;
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

void NoQuarterState::onEnter() const
{
}

void NoQuarterState::onExit() const
{
}

void HasQuarterState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == EventId::INSERT_QUARTER)
        {
            std::cout << m_Machine->getMachineName() << ": Quarter already inserted." << std::endl;
        }
        else if (event->m_Id == EventId::EJECT_QUARTER)
        {
            std::cout << m_Machine->getMachineName() << ": Quarter ejected." << std::endl;
            
            m_Machine->switchToNoQuarterState();
        }
        else if (event->m_Id == EventId::TURN_CRANK)
        {
            std::cout << m_Machine->getMachineName() << ": Crank turned." << std::endl;
            
            m_Machine->dispenseGumball();
            std::cout << m_Machine->getMachineName() << ": A gumball rolled out!" << std::endl;
            
            if(m_Machine->checkSoldOut() == true)
            {
                m_Machine->switchToSoldOutState();
            }
            else
            {
                m_Machine->switchToNoQuarterState();
            }
        }
        else if (event->m_Id == EventId::FILL)
        {
            std::uint32_t* data = (std::uint32_t*)(event->m_Data);
            m_Machine->doFill(*data);
            std::cout << m_Machine->getMachineName() << ": Gumball machine filled with " << *data;
            std::cout << ((*data > 1) ? " gumballs." : " gumball.") << std::endl;
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

void HasQuarterState::onEnter() const
{
}

void HasQuarterState::onExit() const
{
}

