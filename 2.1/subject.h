#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <set>

class Observer;
class Data;

class Subject //did not consider about copy control
{
public:
    Subject() = default;
    void registerObserver(Observer *NewObserver);
    void removeObserver(Observer *ObsoleteObserver);
    void notifyObservers(const Data &NewData) const;

private:
    std::set<Observer *> m_ObserverList;
};

class WeatherSubject : public Subject
{
public:
    WeatherSubject() = default;

    void setMeasurements(float T, float H, float P); //will be called by WeatherStation
};

#endif
