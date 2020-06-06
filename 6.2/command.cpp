#include "command.h"
#include "receiver.h"

using namespace std;

int TaskCommand::m_IdCount = 0;

void TaskCommand::execute() const
{
    if(m_Worker)
    {
        m_Worker->doTask(m_TaskId);
    }
    else
    {
    }
}
