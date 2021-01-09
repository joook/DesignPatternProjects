#include "event.h"

Event::Event(EventId id)
    : m_Id(id)
    , m_Data(nullptr)
{
}

Event::Event(EventId id, void* data)
    : m_Id(id)
    , m_Data(data)
{
}
