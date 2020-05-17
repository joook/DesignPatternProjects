#include "invoker.h"
#include "command.h"

using namespace std;

void Waiter::setCommand(const shared_ptr<Command> &SomeCommand)
{
    m_Command = SomeCommand;
    if(m_Command)
    {
        m_Command->execute();
    }
    else
    {
    }
}

