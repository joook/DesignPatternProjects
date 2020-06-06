#ifndef _INVOKER_H_
#define _INVOKER_H_

#include <memory>
#include <queue>

class Command;

class TaskPublisher
{
public:
    void setCommand(const std::shared_ptr<Command> &SomeCommand);
    std::shared_ptr<Command> getCommand();

private:
    std::queue<std::shared_ptr<Command>> m_CommandQueue;
};

#endif
