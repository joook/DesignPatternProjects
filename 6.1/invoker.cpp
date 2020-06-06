#include "invoker.h"
#include "command.h"

using namespace std;

void Waiter::setCommand(const shared_ptr<Command> &SomeCommand)
{
    m_CommandQueue.push(SomeCommand);
}

void Waiter::orderUp()
{
    while(!m_CommandQueue.empty())
    {
        if(m_CommandQueue.front())
        {
            (m_CommandQueue.front())->execute();
            m_CommandQueue.pop();
        }
        else
        {
            m_CommandQueue.pop();
        }
    }
}
