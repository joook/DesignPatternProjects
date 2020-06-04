#ifndef _STATE_H_
#define _STATE_H_

class GumballMachine;

class State
{
public:
    virtual ~State() = default;

public:
    virtual void insertQuarter(GumballMachine * const MachinePtr) const = 0;
    virtual void ejectQuarter(GumballMachine * const MachinePtr) const = 0;
    virtual void turnCrank(GumballMachine * const MachinePtr) const = 0;
    virtual void fill(GumballMachine * const MachinePtr) const = 0;
};

class SoldOutState : public State
{
public:
    virtual void insertQuarter(GumballMachine * const MachinePtr) const override;
    virtual void ejectQuarter(GumballMachine * const MachinePtr) const override;
    virtual void turnCrank(GumballMachine * const MachinePtr) const override;
    virtual void fill(GumballMachine * const MachinePtr) const override;
};

class NoQuarterState : public State
{
public:
    virtual void insertQuarter(GumballMachine * const MachinePtr) const override;
    virtual void ejectQuarter(GumballMachine * const MachinePtr) const override;
    virtual void turnCrank(GumballMachine * const MachinePtr) const override;
    virtual void fill(GumballMachine * const MachinePtr) const override;
};

class HasQuarterState : public State
{
public:
    virtual void insertQuarter(GumballMachine * const MachinePtr) const override;
    virtual void ejectQuarter(GumballMachine * const MachinePtr) const override;
    virtual void turnCrank(GumballMachine * const MachinePtr) const override;
    virtual void fill(GumballMachine * const MachinePtr) const override;
};

const static std::shared_ptr<State> SoldOutStatePtr = std::make_shared<SoldOutState>();
const static std::shared_ptr<State> NoQuarterStatePtr = std::make_shared<NoQuarterState>();
const static std::shared_ptr<State> HasQuarterStatePtr = std::make_shared<HasQuarterState>();

#endif
