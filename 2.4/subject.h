#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include <functional>

class Data;

class Subject // did not consider about copy control
{
public:
    Subject() = default;
    virtual ~Subject() = default;

public:
    void addHandler(const std::function<void(const Data&)>& func);
    void removeHandler(const std::function<void(const Data&)>& func); // not functional
    void notify(const Data& data) const;

private:
    std::vector<std::function<void(const Data&)>> m_HandlerList;
};

class WeatherSubject : public Subject
{
public:
    WeatherSubject() = default;

public:
    void setMeasurements(float t, float h, float p); // will be called by WeatherStation
};

#endif
