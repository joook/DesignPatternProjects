#include "subject.h"
#include "data.h"

void Subject::addHandler(const std::function<void(const Data&)>& func)
{
    m_HandlerList.push_back(func);
}

void Subject::removeHandler(const std::function<void(const Data&)>& func)
{
}

void Subject::notify(const Data& data) const
{
    for(auto itr = m_HandlerList.cbegin(); itr != m_HandlerList.cend(); itr++)
    {
        (*itr)(data);
    }
}

void WeatherSubject::setMeasurements(float t, float h, float p)
{
    notify(Data(t, h, p));
}

