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

void Subject::notifyObservers() const
{
    for(auto Itr = m_ObserverList.cbegin(); Itr != m_ObserverList.cend(); Itr++)
    {
        (*Itr)->update(this);
    }
}

void WeatherSubject::setMeasurements(float T, float H, float P)
{
    setData(Data(T, H, P));
    notifyObservers();
}

