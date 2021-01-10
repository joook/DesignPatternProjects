#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <memory>
#include <string>

#include "common_types.h"

class State;

class GumballMachine
{
public:
    GumballMachine(const std::string& name);
    ~GumballMachine() = default;
    GumballMachine(const GumballMachine&) = delete;
    GumballMachine& operator=(const GumballMachine&) = delete;
    GumballMachine(GumballMachine&&) = delete;
    GumballMachine&& operator=(const GumballMachine&&) = delete;

public:
    // for user to call
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void fill(std::uint32_t num);

    // for states to call
    void notifyInsertQuarterFailed();
    void notifyInsertQuarterDone();
    void notifyEjectQuarterFailed();
    void notifyEjectQuarterDone();
    void notifyTurnCrankFailed();
    void dispenseGumball();
    void doFill(std::uint32_t num);
    bool checkSoldOut() const { return (m_GumballCount > 0 ? false : true); }

    void switchToState(StateId id);
    bool isValidState(StateId id);
    std::shared_ptr<State> getState(StateId id);
    
    std::string getMachineName() { return m_MachineName; }
    std::string getCurrentStateHint();

private:
    std::string m_MachineName;
    std::shared_ptr<State> m_SoldOutState;
    std::shared_ptr<State> m_NoQuarterState;
    std::shared_ptr<State> m_HasQuarterState;
    std::shared_ptr<State> m_CurrentState;
    std::uint32_t m_GumballCount;
};

#endif
