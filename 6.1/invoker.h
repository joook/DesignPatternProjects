#ifndef _INVOKER_H_
#define _INVOKER_H_

#include <memory>
#include <vector>

class Command;

class Waiter
{
public:
    void setCommand(const std::shared_ptr<Command> &SomeCommand);
    void orderUp() const;

private:
    std::vector<std::shared_ptr<Command>> m_CommandList;
};

#endif
