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
    State(StateId id, const std::string& name, GumballMachine* const machine)
        : m_Id(id)
        , m_Name(name)
        , m_Machine(machine)
    {
    }

    virtual ~State() = default;

    virtual void onEnter() const = 0;
    virtual void onEvent(const std::shared_ptr<Event>& event) const = 0;
    virtual bool isValidSwitch(StateId id) const = 0;
    virtual void onExit() const = 0;
    
    GumballMachine* getContext() const { return m_Machine; }
    std::string getStateName() const { return m_Name; }

private:
    StateId m_Id;
    std::string m_Name;
    GumballMachine* m_Machine;
};

class SoldOutState : public State
{
public:
    SoldOutState(GumballMachine* const machine)
        : State(StateId::SOLD_OUT_STATE, "sold out", machine)
    {
    }

    virtual void onEnter() const override;
    virtual void onEvent(const std::shared_ptr<Event>& event) const override;
    virtual bool isValidSwitch(StateId id) const override;
    virtual void onExit() const override;
};

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine* const machine)
        : State(StateId::NO_QUARTER_STATE, "no quarter", machine)
    {
    }

    virtual void onEnter() const override;
    virtual void onEvent(const std::shared_ptr<Event>& event) const override;
    virtual bool isValidSwitch(StateId id) const override;
    virtual void onExit() const override;
};

class HasQuarterState : public State
{
public:
    HasQuarterState(GumballMachine* const machine)
        : State(StateId::HAS_QUARTER_STATE, "has quarter", machine)
    {
    }

    virtual void onEnter() const override;
    virtual void onEvent(const std::shared_ptr<Event>& event) const override;
    virtual bool isValidSwitch(StateId id) const override;
    virtual void onExit() const override;
};

#endif
