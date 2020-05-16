#include "singleton.h"
#include <iostream>

using namespace std;

mutex Singleton::m_Mutex;
int Singleton::m_Id = 0;

Singleton &Singleton::getInstance()
{
    //in my experiments, it works well without lock, but I'm not sure
    //lock_guard<mutex> Lock(m_Mutex);
    static Singleton Instance;
    return Instance;
}

void Singleton::printId()
{
    cout << m_Id;
}

