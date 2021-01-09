#include <iostream>
#include <memory>
#include "context.h"
#include "state.h"
#include "event.h"

GumballMachine::GumballMachine(const std::string& name)
    : m_MachineName(name)
    , m_SoldOutState(std::make_shared<SoldOutState>(this))
    , m_NoQuarterState(std::make_shared<NoQuarterState>(this))
    , m_HasQuarterState(std::make_shared<HasQuarterState>(this))
    , m_CurrentState(m_SoldOutState)
    , m_GumballCount(0)
{
}

void GumballMachine::insertQuarter()
{
    m_CurrentState->onEvent(std::make_shared<Event>(EventId::INSERT_QUARTER));
}

void GumballMachine::ejectQuarter()
{
    m_CurrentState->onEvent(std::make_shared<Event>(EventId::EJECT_QUARTER));
}

void GumballMachine::turnCrank()
{
    m_CurrentState->onEvent(std::make_shared<Event>(EventId::TURN_CRANK));
}

void GumballMachine::fill(std::uint32_t num)
{
    m_CurrentState->onEvent(std::make_shared<Event>(EventId::FILL, (void*)(&num)));
}

void GumballMachine::dispenseGumball()
{
    m_GumballCount--;
}

void GumballMachine::doFill(std::uint32_t num)
{
    m_GumballCount += num;
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
