#ifndef _STATE_H_
#define _STATE_H_

#include <memory>

class GumballMachine;
class Event;

class State //did not consider about copy control
{
public:
    State(GumballMachine* const machine)
    : m_Machine(machine)
    {
    }

    virtual ~State() = default;

public:
    virtual void onEnter() const = 0;
    virtual void onEvent(const std::shared_ptr<Event>& event) const = 0;
    virtual void onExit() const = 0;

public:
    GumballMachine* m_Machine;
};

class SoldOutState : public State
{
public:
    SoldOutState(GumballMachine* const machine)
    : State(machine)
    {
    }

public:
    virtual void onEnter() const override;
    virtual void onEvent(const std::shared_ptr<Event>& event) const override;
    virtual void onExit() const override;
};

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine* const machine)
    : State(machine)
    {
    }

public:
    virtual void onEnter() const override;
    virtual void onEvent(const std::shared_ptr<Event>& event) const override;
    virtual void onExit() const override;
};

class HasQuarterState : public State
{
public:
    HasQuarterState(GumballMachine* const machine)
    : State(machine)
    {
    }

public:
    virtual void onEnter() const override;
    virtual void onEvent(const std::shared_ptr<Event>& event) const override;
    virtual void onExit() const override;
};

#endif
