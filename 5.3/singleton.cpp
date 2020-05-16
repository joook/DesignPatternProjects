#include "singleton.h"
#include <iostream>

using namespace std;

//this Singleton is not(and cannot be) created inside class,
//I'm not sure if it is only created once,
//though in my experiments, it works well
Singleton *Singleton::m_Instance = new Singleton();
int Singleton::m_Id = 0;

void Singleton::printId()
{
    cout << m_Id;
}

