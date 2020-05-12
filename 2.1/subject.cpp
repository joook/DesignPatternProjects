#include "subject.h"
#include "observer.h"
#include "data.h"

void Subject::registerObserver(Observer *const NewObserverPtr)
{
    if(NewObserverPtr != nullptr)
    {
        m_ObserverList.insert(NewObserverPtr);
    }
    else
    {
    }
}

void Subject::removeObserver(Observer *const ObsoleteObserver)
{
    if(ObsoleteObserver != nullptr)
    {
        m_ObserverList.erase(ObsoleteObserver);
    }
    else
    {
    }
}

void Subject::notifyObservers(const Data &NewData) const
{
    for(auto Itr = m_ObserverList.cbegin(); Itr != m_ObserverList.cend(); Itr++)
    {
        (*Itr)->update(NewData);
    }
}

void WeatherSubject::setMeasurements(float T, float H, float P)
{
    notifyObservers(Data(T, H, P));
}

