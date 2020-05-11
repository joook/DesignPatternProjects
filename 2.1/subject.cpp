#include "subject.h"
#include "observer.h"
#include "data.h"

void Subject::registerObserver(Observer *NewObserverPtr)
{
    if(NewObserverPtr != nullptr)
    {
        m_ObserverList.insert(NewObserverPtr);
        NewObserverPtr->setSubject(this);
    }
    else
    {
    }
}

void Subject::removeObserver(Observer *ObsoleteObserver)
{
    if(ObsoleteObserver != nullptr)
    {
        m_ObserverList.erase(ObsoleteObserver);
        ObsoleteObserver->clearSubject();
    }
    else
    {
    }
}

void Subject::notifyObservers(const Data &NewData) const
{
    for(auto Itr = m_ObserverList.begin(); Itr != m_ObserverList.cend(); Itr++)
    {
        (*Itr)->update(NewData);
    }
}

void WeatherSubject::setMeasurements(float T, float H, float P)
{
    notifyObservers(Data(T, H, P));
}

