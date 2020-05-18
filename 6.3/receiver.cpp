#include "receiver.h"
#include <iostream>

using namespace std;

void Receiver::doTask(const int TaskId) const
{
    cout << m_Name << " get task-" << TaskId << " done." << endl;
}
