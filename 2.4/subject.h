#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <map>
#include <functional>

class Data;

class Subject // did not consider about copy control
{
public:
    Subject() = default;
    virtual ~Subject() = default;

public:
    std::uint32_t addHandler(const std::function<void(const Data&)>& func);
    void removeHandler(std::uint32_t id);
    void notify(const Data& data) const;

private:
    std::uint32_t getUniqueId()
    {
        static std::uint32_t id = 0;
        if (id < 2^32-1)
        {
            id++;
        }
        else
        {
            id = 0;
        }
        return id;
    }

private:
    std::map<std::uint32_t, std::function<void(const Data&)>> m_HandlerList;
};

class WeatherSubject : public Subject
{
public:
    WeatherSubject() = default;

public:
    void setMeasurements(float t, float h, float p); // will be called by WeatherStation
};

#endif
