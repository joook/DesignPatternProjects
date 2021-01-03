#ifndef _EVENT_H_
#define _EVENT_H_

#include <cstdint>

enum EventId : std::uint32_t
{
    INSERT_QUARTER = 0,
    EJECT_QUARTER = 1,
    TURN_CRANK = 2,
    FILL = 3,
};

class Event //did not consider about copy control
{
public:
    Event(std::uint32_t id);
    Event(std::uint32_t id, void* data);

public:
    std::uint32_t m_Id;
    void* m_Data;
};

#endif
