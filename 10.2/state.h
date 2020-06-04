#ifndef _STATE_H_
#define _STATE_H_

class GumballMachine;

class State //did not consider about copy control
{
public:
    State(GumballMachine * const MachinePtr)
    : m_MachinePtr(MachinePtr)
    {
    }

    virtual ~State() = default;

public:
    virtual void insertQuarter() const = 0;
    virtual void ejectQuarter() const = 0;
    virtual void turnCrank() const = 0;
    virtual void fill() const = 0;

public:
    GumballMachine * m_MachinePtr;
};

class SoldOutState : public State
{
public:
    SoldOutState(GumballMachine * const MachinePtr)
    : State(MachinePtr)
    {
    }

public:
    virtual void insertQuarter() const override;
    virtual void ejectQuarter() const override;
    virtual void turnCrank() const override;
    virtual void fill() const override;
};

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine * const MachinePtr)
    : State(MachinePtr)
    {
    }

public:
    virtual void insertQuarter() const override;
    virtual void ejectQuarter() const override;
    virtual void turnCrank() const override;
    virtual void fill() const override;
};

class HasQuarterState : public State
{
public:
    HasQuarterState(GumballMachine * const MachinePtr)
    : State(MachinePtr)
    {
    }

public:
    virtual void insertQuarter() const override;
    virtual void ejectQuarter() const override;
    virtual void turnCrank() const override;
    virtual void fill() const override;
};

#endif
