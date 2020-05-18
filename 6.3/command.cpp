#include "command.h"
#include "receiver.h"

using namespace std;

int ConcreteCommand::m_IdCount = 0;

void ConcreteCommand::execute() const
{
    if(m_Receiver)
    {
        m_Receiver->doTask(m_Id);
    }
    else
    {
    }
}
