#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <memory>

class Chef;

class Command
{
public:
    Command(const std::shared_ptr<Chef> &SomeChef)
    : m_Chef(SomeChef)
    {
    }

    virtual void execute() const = 0;

public:
    std::shared_ptr<Chef> m_Chef;
};

class OrderCommand : public Command
{
public:
    OrderCommand(const std::shared_ptr<Chef> &SomeChef)
    : Command(SomeChef)
    {
    }

    virtual void execute() const override;
};

#endif
