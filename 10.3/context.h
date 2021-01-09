#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <memory>
#include <string>

class State;

class GumballMachine
{
public:
    GumballMachine(const std::string& name);
    ~GumballMachine() = default;

public:
    // for user to call
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void fill(std::uint32_t num);

    // for states to call
    void dispenseGumball();
    void doFill(std::uint32_t num);

    bool checkSoldOut() const
    {
        return (m_GumballCount > 0 ? false : true);
    }

    void switchToSoldOutState();
    void switchToNoQuarterState();
    void switchToHasQuarterState();
    
    std::string getMachineName() { return m_MachineName; }

private:
    std::string m_MachineName;
    std::shared_ptr<State> m_SoldOutState;
    std::shared_ptr<State> m_NoQuarterState;
    std::shared_ptr<State> m_HasQuarterState;
    std::shared_ptr<State> m_CurrentState;
    std::uint32_t m_GumballCount;
};

#endif
