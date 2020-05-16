#include "singleton.h"
#include <iostream>

using namespace std;

Singleton *Singleton::m_Instance = nullptr;
mutex Singleton::m_Mutex;
int Singleton::m_Id = 0;

Singleton *Singleton::getInstance()
{
    lock_guard<mutex> Lock(m_Mutex);
    if(m_Instance == nullptr)
    {
        m_Instance = new Singleton();
    }
    else
    {
    }
    return m_Instance;
}

void Singleton::printId()
{
    cout << m_Id;
}

