#include "singleton.h"
#include <thread>  //add -pthread if you use gcc/g++ to compile it
#include <iostream>

using namespace std;

void runThread()
{
    Singleton::getInstance().printId();
}

int main()
{
    for(int i = 0; i < 50; i++)
    {
        thread Thread1(runThread);
        thread Thread2(runThread);
        Thread1.join();
        Thread2.join();
    }
    cout << endl;

    return 0;
}
