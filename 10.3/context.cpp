#include <iostream>
#include <memory>
#include "context.h"
#include "state.h"
#include "event.h"

GumballMachine::GumballMachine()
: m_SoldOutState(std::make_shared<SoldOutState>(this))
, m_NoQuarterState(std::make_shared<NoQuarterState>(this))
, m_HasQuarterState(std::make_shared<HasQuarterState>(this))
, m_CurrentState(m_SoldOutState)
, m_GumballCount(0)
{
}

void GumballMachine::insertQuarter()
{
    m_CurrentState->onEvent(std::make_shared<Event>(INSERT_QUARTER));
}

void GumballMachine::ejectQuarter()
{
    m_CurrentState->onEvent(std::make_shared<Event>(EJECT_QUARTER));
}

void GumballMachine::turnCrank()
{
    m_CurrentState->onEvent(std::make_shared<Event>(TURN_CRANK));
}

void GumballMachine::fill(std::uint32_t num)
{
    m_GumballCount += num;
    if(m_GumballCount > 0)
    {
        m_CurrentState->onEvent(std::make_shared<Event>(FILL));
    }
    else
    {
    }
}

void GumballMachine::dispenseGumball()
{
    std::cout << "A gumball rolled out!" << std::endl;
    m_GumballCount--;
}

void GumballMachine::switchToSoldOutState()
{
    m_CurrentState->onExit();
    m_SoldOutState->onEnter();
    m_CurrentState = m_SoldOutState;
}

void GumballMachine::switchToNoQuarterState()
{
    m_CurrentState->onExit();
    m_NoQuarterState->onEnter();
    m_CurrentState = m_NoQuarterState;
}

void GumballMachine::switchToHasQuarterState()
{
    m_CurrentState->onExit();
    m_HasQuarterState->onEnter();
    m_CurrentState = m_HasQuarterState;
}
