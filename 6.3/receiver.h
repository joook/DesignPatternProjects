#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <string>

class Receiver
{
public:
    Receiver(const std::string &Name) : m_Name(Name) {}
    virtual void doTask(const int TaskId) const;

private:
    std::string m_Name;
};

#endif
