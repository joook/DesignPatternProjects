#include "subject.h"
#include "data.h"

std::uint32_t Subject::addHandler(const std::function<void(const Data&)>& func)
{
    auto id = getUniqueId();
    m_HandlerList.emplace(id, func);
    return id;
}

void Subject::removeHandler(std::uint32_t id)
{
    m_HandlerList.erase(id);
}

void Subject::notify(const Data& data) const
{
    for(auto itr = m_HandlerList.cbegin(); itr != m_HandlerList.cend(); itr++)
    {
        (itr->second)(data);
    }
}

void WeatherSubject::setMeasurements(float t, float h, float p)
{
    notify(Data(t, h, p));
}

