#include <iostream>

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

void GumballMachine::notifyInsertQuarterFailed()
{
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", can not insert." << std::endl;
}

void GumballMachine::notifyInsertQuarterDone()
{
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", you inserted a quarter." << std::endl;
}

void GumballMachine::notifyEjectQuarterFailed()
{
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", can not eject." << std::endl;
}

void GumballMachine::notifyEjectQuarterDone()
{
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", you ejected a quarter." << std::endl;
}

void GumballMachine::notifyTurnCrankFailed()
{
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", can not turn crank." << std::endl;
}

void GumballMachine::dispenseGumball()
{
    m_GumballCount--;
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", crank turned, A gumball rolled out!" << std::endl;
}

void GumballMachine::doFill(std::uint32_t num)
{
    m_GumballCount += num;
    std::cout << getMachineName() << ": " << getCurrentStateHint();
    std::cout << ", gumball machine filled with " << num << " gumball(s)." << std::endl;
}

void GumballMachine::switchToState(StateId id)
{
    if ((isValidState(id))
        && (m_CurrentState->isValidSwitch(id)))
    {
        m_CurrentState->onExit();
        m_CurrentState = getState(id);
        m_CurrentState->onEnter();
    }
    else
    {
        // do nothing
    }
}

bool GumballMachine::isValidState(StateId id)
{
    if ((id == StateId::SOLD_OUT_STATE)
        || (id == StateId::NO_QUARTER_STATE)
        || (id == StateId::HAS_QUARTER_STATE))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::shared_ptr<State> GumballMachine::getState(StateId id)
{
    std::shared_ptr<State> state{nullptr};
    
    if (id == StateId::SOLD_OUT_STATE)
    {
        state = m_SoldOutState;
    }
    else if (id == StateId::NO_QUARTER_STATE)
    {
        state = m_NoQuarterState;
    }
    else if (id == StateId::HAS_QUARTER_STATE)
    {
        state = m_HasQuarterState;
    }
    else
    {
        // throw excption
    }
    
    return state;
}

std::string GumballMachine::getCurrentStateHint()
{
    return "current state is <"+m_CurrentState->getStateName()+">";
}



