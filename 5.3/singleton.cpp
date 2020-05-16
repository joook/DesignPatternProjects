#include "singleton.h"
#include <iostream>

using namespace std;

Singleton *Singleton::m_Instance = new Singleton();
int Singleton::m_Id = 0;

void Singleton::printId()
{
    cout << m_Id;
}

