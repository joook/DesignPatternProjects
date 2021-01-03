#include "event.h"

Event::Event(std::uint32_t id)
    : m_Id(id)
    , m_Data(nullptr)
{
}

Event::Event(std::uint32_t id, void* data)
    : m_Id(id)
    , m_Data(data)
{
}
