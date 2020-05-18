#include "invoker.h"
#include "command.h"

using namespace std;

void Editor::setCommand(const shared_ptr<Command> &SomeCommand)
{
    if(SomeCommand)
    {
        SomeCommand->execute();
        m_HistoryCommandStack.push(SomeCommand);
    }
    else
    {
    }
}

void Editor::undo()
{
    if(!m_HistoryCommandStack.empty())
    {
        shared_ptr<Command> SomeCommand = m_HistoryCommandStack.top();
        SomeCommand->undo();
        m_HistoryCommandStack.pop();

        m_RedoCommandStack.push(SomeCommand);
    }
    else
    {
    }
}

void Editor::redo()
{
    if(!m_RedoCommandStack.empty())
    {
        shared_ptr<Command> SomeCommand = m_RedoCommandStack.top();
        SomeCommand->execute();
        m_RedoCommandStack.pop();

        m_HistoryCommandStack.push(SomeCommand);
    }
    else
    {
    }
}
