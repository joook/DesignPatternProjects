#include "invoker.h"
#include "command.h"

using namespace std;

void Waiter::setCommand(const shared_ptr<Command> &SomeCommand)
{
    m_CommandList.push_back(SomeCommand);
}

void Waiter::orderUp() const
{
    for(auto Itr = m_CommandList.begin(); Itr != m_CommandList.cend(); Itr++)
    {
        if(*Itr)
        {
            (*Itr)->execute();
        }
        else
        {
        }
    }
}
