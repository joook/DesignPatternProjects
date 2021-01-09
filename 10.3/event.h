#ifndef _EVENT_H_
#define _EVENT_H_

#include <cstdint> // std::uint32_t

enum class EventId : std::uint32_t
{
    INSERT_QUARTER = 0,
    EJECT_QUARTER = 1,
    TURN_CRANK = 2,
    FILL = 3,
};

class Event // did not consider about copy control
{
public:
    Event(EventId id);
    Event(EventId id, void* data);
    ~Event() = default;

public:
    EventId m_Id;
    void* m_Data;
};

#endif
