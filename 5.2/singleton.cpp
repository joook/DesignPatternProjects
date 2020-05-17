#include "singleton.h"
#include <iostream>

using namespace std;

int Singleton::m_Id = 0;

Singleton &Singleton::getInstance()
{
    //if multiple threads attempt to initialize the same 
    //static local variable concurrently,
    //the initialization occurs exactly once,
    //it is guaranteed since c++11
    static Singleton Instance;
    return Instance;
}

void Singleton::printId()
{
    cout << m_Id;
}

