#include "subject.h"
#include "observer.h"
#include "data.h"

void Observable::registerObserver(Observer *const NewObserverPtr)
{
    if(NewObserverPtr != nullptr)
    {
        m_ObserverList.insert(NewObserverPtr);
    }
    else
    {
    }
}

void Observable::removeObserver(Observer *const ObsoleteObserver)
{
    if(ObsoleteObserver != nullptr)
    {
        m_ObserverList.erase(ObsoleteObserver);
    }
    else
    {
    }
}

void Observable::notifyObservers(const Data &NewData) const
{
    for(auto Itr = m_ObserverList.cbegin(); Itr != m_ObserverList.cend(); Itr++)
    {
        (*Itr)->update(NewData);
    }
}

void RedChicken::layEggs(unsigned int EggNum)
{
    m_Observable->notifyObservers(Data("red chicken egg", EggNum));
}

void GreyChicken::layEggs(unsigned int EggNum)
{
    m_Observable->notifyObservers(Data("grey chicken egg", EggNum));
}

void BlackChicken::layEggs(unsigned int EggNum)
{
    m_Observable->notifyObservers(Data("black chicken egg", EggNum));
}

