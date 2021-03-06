#ifndef _EVENT_H_
#define _EVENT_H_

#include "common_types.h"

class Event // did not consider about copy control
{
public:
    Event(EventId id);
    Event(EventId id, void* data);
    ~Event() = default;
    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;
    Event(Event&&) = delete;
    Event&& operator=(const Event&&) = delete;

public:
    EventId m_Id;
    void* m_Data;
};

#endif
