#ifndef _STATE_H_
#define _STATE_H_

#include <memory>
#include <string>

#include "common_types.h"

class GumballMachine;
class Event;

class State // did not consider about copy control
{
public:
    State(StateId id, const std::string& name)
        : m_Id(id)
        , m_Name(name)
    {
    }

    virtual ~State() = default;

    virtual void onEnter(GumballMachine* const machine) const = 0;
    virtual bool isValidSwitch(StateId id) const = 0;
    virtual void onExit(GumballMachine* const machine) const = 0;
    
    virtual void onInsertQuarterEvent(GumballMachine* const machine) const = 0;
    virtual void onEjectQuarterEvent(GumballMachine* const machine) const = 0;
    virtual void onTurnCrankEvent(GumballMachine* const machine) const = 0;
    virtual void onFillEvent(GumballMachine* const machine, std::uint32_t num) const = 0;
    
    std::string getStateName() const { return m_Name; }

private:
    StateId m_Id;
    std::string m_Name;
};

class SoldOutState : public State
{
public:
    SoldOutState()
        : State(StateId::SOLD_OUT_STATE, "sold out")
    {
    }

    virtual void onEnter(GumballMachine* const machine) const override;
    virtual bool isValidSwitch(StateId id) const override;
    virtual void onExit(GumballMachine* const machine) const override;
    
    virtual void onInsertQuarterEvent(GumballMachine* const machine) const override;
    virtual void onEjectQuarterEvent(GumballMachine* const machine) const override;
    virtual void onTurnCrankEvent(GumballMachine* const machine) const override;
    virtual void onFillEvent(GumballMachine* const machine, std::uint32_t num) const override;
};

class NoQuarterState : public State
{
public:
    NoQuarterState()
        : State(StateId::NO_QUARTER_STATE, "no quarter")
    {
    }

    virtual void onEnter(GumballMachine* const machine) const override;
    virtual bool isValidSwitch(StateId id) const override;
    virtual void onExit(GumballMachine* const machine) const override;
    
    virtual void onInsertQuarterEvent(GumballMachine* const machine) const override;
    virtual void onEjectQuarterEvent(GumballMachine* const machine) const override;
    virtual void onTurnCrankEvent(GumballMachine* const machine) const override;
    virtual void onFillEvent(GumballMachine* const machine, std::uint32_t num) const override;
};

class HasQuarterState : public State
{
public:
    HasQuarterState()
        : State(StateId::HAS_QUARTER_STATE, "has quarter")
    {
    }

    virtual void onEnter(GumballMachine* const machine) const override;
    virtual bool isValidSwitch(StateId id) const override;
    virtual void onExit(GumballMachine* const machine) const override;
    
    virtual void onInsertQuarterEvent(GumballMachine* const machine) const override;
    virtual void onEjectQuarterEvent(GumballMachine* const machine) const override;
    virtual void onTurnCrankEvent(GumballMachine* const machine) const override;
    virtual void onFillEvent(GumballMachine* const machine, std::uint32_t num) const override;
};

#endif
