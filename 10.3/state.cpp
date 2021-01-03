#include <iostream>
#include <memory>
#include "state.h"
#include "context.h"
#include "event.h"

void SoldOutState::onEvent(const std::shared_ptr<Event>& event) const
{
    if (event)
    {
        if (event->m_Id == INSERT_QUARTER)
        {
            std::cout << "Gumball sold out, can not insert." << std::endl;
        }
        else if (event->m_Id == EJECT_QUARTER)
        {
            std::cout << "Gumball sold out, can not eject." << std::endl;
        }
        else if (event->m_Id == TURN_CRANK)
        {
            std::cout << "Gumball sold out, can not turn crank." << std::endl;
        }
        else if (event->m_Id == FILL)
        {
            std::cout << "Gumball machine filled." << std::endl;
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
        if (event->m_Id == INSERT_QUARTER)
        {
            std::cout << "You inserted a quarter." << std::endl;
            m_Machine->switchToHasQuarterState();
        }
        else if (event->m_Id == EJECT_QUARTER)
        {
            std::cout << "No quarter inserted, can not eject." << std::endl;
        }
        else if (event->m_Id == TURN_CRANK)
        {
            std::cout << "No quarter inserted, can not turn crank." << std::endl;
        }
        else if (event->m_Id == FILL)
        {
            std::cout << "Gumball machine filled." << std::endl;
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
        if (event->m_Id == INSERT_QUARTER)
        {
            std::cout << "Quarter already inserted." << std::endl;
        }
        else if (event->m_Id == EJECT_QUARTER)
        {
            std::cout << "Quarter ejected." << std::endl;
            m_Machine->switchToNoQuarterState();
        }
        else if (event->m_Id == TURN_CRANK)
        {
            std::cout << "Crank turned." << std::endl;
            m_Machine->dispenseGumball();
            if(m_Machine->checkSoldOut() == true)
            {
                m_Machine->switchToSoldOutState();
            }
            else
            {
                m_Machine->switchToNoQuarterState();
            }
        }
        else if (event->m_Id == FILL)
        {
            std::cout << "Gumball machine filled." << std::endl;
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

