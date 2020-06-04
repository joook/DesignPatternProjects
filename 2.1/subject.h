#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <set>

class Observer;
class Data;

class Subject //did not consider about copy control
{
public:
    Subject() = default;
    virtual ~Subject() = default;

public:
    void registerObserver(Observer *const NewObserver);
    void removeObserver(Observer *const ObsoleteObserver);
    void notifyObservers(const Data &NewData) const;

private:
    std::set<Observer *> m_ObserverList;
};

class WeatherSubject : public Subject
{
public:
    WeatherSubject() = default;
    virtual ~WeatherSubject() = default;

public:
    void setMeasurements(float T, float H, float P); //will be called by WeatherStation
};

#endif
