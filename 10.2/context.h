#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <memory>

class State;

class GumballMachine
{
public:
    GumballMachine();

public:
    //for user to call
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void fill(unsigned int Num);

    //for states to call
    void dispenseGumball();

    bool checkSoldOut() const
    {
        return (m_GumballCount > 0 ? false : true);
    }

    void setState(const std::shared_ptr<State> &StatePtr)
    {
        m_StatePtr = StatePtr;
    }

    std::shared_ptr<State> getSoldOutStatePtr() { return m_SoldOutStatePtr; }
    std::shared_ptr<State> getNoQuarterStatePtr() { return m_NoQuarterStatePtr; }
    std::shared_ptr<State> getHasQuarterStatePtr() { return m_HasQuarterStatePtr; }

private:
    std::shared_ptr<State> m_SoldOutStatePtr;
    std::shared_ptr<State> m_NoQuarterStatePtr;
    std::shared_ptr<State> m_HasQuarterStatePtr;
    std::shared_ptr<State> m_StatePtr;
    unsigned int m_GumballCount = 0;
};

#endif
