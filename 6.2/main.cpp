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

void runWorkerThread(TaskPublisher &Publisher)
{
    while(true)
    {
        //pop a task from queue
        Mutex.lock();
        std::shared_ptr<Command> Task = Publisher.getCommand();
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
    Worker Worker1("Steve");
    Worker Worker2("Jack");
    TaskPublisher Publisher;

    thread WorkerThread1(runWorkerThread, ref(Publisher));
    thread WorkerThread2(runWorkerThread, ref(Publisher));

    for(int i = 0; i < 10; i++)
    {
        //create a task
        shared_ptr<Command> Task;
        if(i % 2 ==0)
        {
            Task = make_shared<TaskCommand>(&Worker1);
        }
        else
        {
            Task = make_shared<TaskCommand>(&Worker2);
        }

        //push task into queue
        Mutex.lock();
        Publisher.setCommand(Task);
        Mutex.unlock();

        this_thread::sleep_for(chrono::seconds(1));
    }

    WorkerThread1.join();
    WorkerThread2.join();

    return 0;
}



