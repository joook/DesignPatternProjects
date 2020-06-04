#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <memory>

class Chef;

class Command
{
public:
    Command(Chef * const SomeChef)
    : m_Chef(SomeChef)
    {
    }

    virtual ~Command() = default;

public:
    virtual void execute() const = 0;

protected:
    Chef *m_Chef;
};

class OrderCommand : public Command
{
public:
    OrderCommand(Chef * const SomeChef)
    : Command(SomeChef)
    {
    }

public:
    virtual void execute() const override;
};

#endif
