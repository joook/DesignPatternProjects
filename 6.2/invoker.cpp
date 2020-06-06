#include "invoker.h"
#include "command.h"
#include <iostream>

using namespace std;

void TaskPublisher::setCommand(const shared_ptr<Command> &SomeCommand)
{
    cout << "Boss published new task." << endl;
    m_CommandQueue.push(SomeCommand);
}

std::shared_ptr<Command> TaskPublisher::getCommand()
{
    shared_ptr<Command> Ptr;
    if(!m_CommandQueue.empty())
    {
        Ptr = m_CommandQueue.front();
        m_CommandQueue.pop();
    }
    else
    {
    }
    return Ptr;
}
