#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <set>
#include "data.h"

class Observer;

class Subject //did not consider about copy control
{
public:
    Subject() = default;
    void registerObserver(Observer *const NewObserver);
    void removeObserver(Observer *const ObsoleteObserver);
    void notifyObservers() const;
    virtual Data getData() const = 0;
    virtual void setData(const Data &NewData) = 0;

private:
    std::set<Observer *> m_ObserverList;
};

class WeatherSubject : public Subject
{
public:
    WeatherSubject() = default;
    virtual Data getData() const override { return m_Data; }
    virtual void setData(const Data &NewData) override { m_Data = NewData; }

    void setMeasurements(float T, float H, float P); //will be called by WeatherStation

private:
    Data m_Data;
};

#endif
