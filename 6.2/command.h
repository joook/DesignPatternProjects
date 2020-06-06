#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <memory>
#include <string>

class Worker;

class Command
{
public:
    virtual ~Command() = default;

public:
    virtual void execute() const = 0;
};

class TaskCommand : public Command //did not consider about copy control
{
public:
    TaskCommand(Worker * const SomeWorker)
    : m_Worker(SomeWorker)
    , m_TaskId(++m_IdCount)
    {
    }

public:
    virtual void execute() const override;

private:
    Worker *m_Worker;
    int m_TaskId;

    static int m_IdCount;
};

#endif
