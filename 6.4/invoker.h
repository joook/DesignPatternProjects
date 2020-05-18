#ifndef _INVOKER_H_
#define _INVOKER_H_

#include <memory>
#include <stack>

class Command;

class Editor
{
public:
    void setCommand(const std::shared_ptr<Command> &SomeCommand);
    void undo();
    void redo();

private:
    std::stack<std::shared_ptr<Command>> m_HistoryCommandStack;
    std::stack<std::shared_ptr<Command>> m_RedoCommandStack;
};

#endif
