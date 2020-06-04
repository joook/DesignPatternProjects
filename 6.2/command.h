#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <memory>
#include <string>

class Chef;

//did not consider about copy control
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
    OrderCommand(Chef * const SomeChef, const std::string &Name)
    : Command(SomeChef)
    , m_Name(Name)
    {
    }

public:
    virtual void execute() const override;

private:
    std::string m_Name;
};

#endif
