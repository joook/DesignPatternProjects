#include "singleton.h"
#include <iostream>

using namespace std;

atomic<Singleton *> Singleton::m_Instance(nullptr);
mutex Singleton::m_Mutex;
int Singleton::m_Id = 0;

Singleton *Singleton::getInstance()
{
    Singleton *TempPtr = m_Instance.load(memory_order_relaxed);
    atomic_thread_fence(memory_order_acquire);
    if(TempPtr == nullptr)
    {
        lock_guard<mutex> Lock(m_Mutex);
        TempPtr = m_Instance.load(memory_order_relaxed);
        if(TempPtr == nullptr)
        {
            TempPtr = new Singleton();
            atomic_thread_fence(memory_order_release);
            m_Instance.store(TempPtr, memory_order_relaxed);
        }
        else
        {
        }
    }
    else
    {
    }
    return TempPtr;
}

void Singleton::printId()
{
    cout << m_Id;
}

