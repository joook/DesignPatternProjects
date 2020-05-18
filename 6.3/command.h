#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <memory>
#include <string>

class Receiver;

//did not consider about copy control
class Command
{
public:
    Command(Receiver * const SomeReceiver)
    : m_Receiver(SomeReceiver)
    {
    }

    virtual void execute() const = 0;

public:
    Receiver *m_Receiver;
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver * const SomeReceiver)
    : Command(SomeReceiver)
    , m_Id(++m_IdCount)
    {
    }

    virtual void execute() const override;

private:
    static int m_IdCount;
    int m_Id;
};

#endif
