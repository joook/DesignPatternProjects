#ifndef _INVOKER_H_
#define _INVOKER_H_

#include <memory>

class Command;

class Waiter
{
public:
    void setCommand(const std::shared_ptr<Command> &SomeCommand);

private:
    std::shared_ptr<Command> m_Command;
};

#endif
