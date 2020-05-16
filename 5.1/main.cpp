#include "singleton.h"
#include <thread>
#include <iostream>

using namespace std;

void runThread()
{
    for(int i = 0; i < 50; i++)
    {
        Singleton::getInstance()->printId();
    }
    cout << endl;
}

int main()
{
    thread Thread1(runThread);
    thread Thread2(runThread);

    Thread1.join();
    Thread2.join();
    return 0;
}
