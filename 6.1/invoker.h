#ifndef _INVOKER_H_
#define _INVOKER_H_

#include <memory>
#include <queue>

class Command;

class Waiter
{
public:
    void setCommand(const std::shared_ptr<Command> &SomeCommand);
    void orderUp();

private:
    std::queue<std::shared_ptr<Command>> m_CommandQueue;
};

#endif
