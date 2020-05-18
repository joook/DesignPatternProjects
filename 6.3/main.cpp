#include <iostream>
#include <memory>
#include <mutex>
#include <thread> //add -pthread if you use gcc/g++ to compile it
#include <chrono>
#include "receiver.h"
#include "command.h"
#include "invoker.h"

using namespace std;

mutex Mutex;

void runWorkerThread(Invoker &TaskList)
{
    while(true)
    {
        //pop a task from queue
        Mutex.lock();
        std::shared_ptr<Command> Task = TaskList.getCommand();
        Mutex.unlock();

        //do task
        if(Task)
        {
            Task->execute();
        }
        else
        {
        }

        this_thread::sleep_for(chrono::seconds(3));
    }
}

//simulate a boss
int main()
{
    Receiver Worker1("Steve");
    Receiver Worker2("Jack");
    Invoker TaskList;

    thread WorkerThread1(runWorkerThread, ref(TaskList));
    thread WorkerThread2(runWorkerThread, ref(TaskList));

    for(int i = 0; i < 10; i++)
    {
        //create a task
        shared_ptr<Command> Task;
        if(i % 2 ==0)
        {
            Task = make_shared<ConcreteCommand>(&Worker1);
        }
        else
        {
            Task = make_shared<ConcreteCommand>(&Worker2);
        }

        //push task into queue
        Mutex.lock();
        TaskList.setCommand(Task);
        Mutex.unlock();

        this_thread::sleep_for(chrono::seconds(1));
    }

    WorkerThread1.join();
    WorkerThread2.join();

    return 0;
}



