#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <set>

class Observer;
class Data;

class Subject
{
public:
    Subject() = default;
    virtual ~Subject() = default;
    virtual void registerObserver(Observer *const NewObserver) = 0;
    virtual void removeObserver(Observer *const ObsoleteObserver) = 0;
    virtual void notifyObservers(const Data &NewData) const = 0;
};

class Observable : public Subject //did not consider about copy control
{
public:
    Observable() = default;
    virtual void registerObserver(Observer *const NewObserver) override;
    virtual void removeObserver(Observer *const ObsoleteObserver) override;
    virtual void notifyObservers(const Data &NewData) const override;

private:
    std::set<Observer *> m_ObserverList;
};

class RedChicken : public Subject
{
public:
    RedChicken()
    : m_Observable(new Observable)
    {
    }

    virtual ~RedChicken()
    {
        delete m_Observable;
    }

    virtual void registerObserver(Observer *const NewObserver) override
    {
        m_Observable->registerObserver(NewObserver);
    }

    virtual void removeObserver(Observer *const ObsoleteObserver) override
    {
        m_Observable->removeObserver(ObsoleteObserver);
    }

    virtual void notifyObservers(const Data &NewData) const override
    {
        m_Observable->notifyObservers(NewData);
    }

    void layEggs(unsigned int EggNum); //will be called by Nature

private:
    Observable *m_Observable;
};

class GreyChicken : public Subject
{
public:
    GreyChicken()
    : m_Observable(new Observable)
    {
    }

    virtual ~GreyChicken()
    {
        delete m_Observable;
    }

    virtual void registerObserver(Observer *const NewObserver) override
    {
        m_Observable->registerObserver(NewObserver);
    }

    virtual void removeObserver(Observer *const ObsoleteObserver) override
    {
        m_Observable->removeObserver(ObsoleteObserver);
    }

    virtual void notifyObservers(const Data &NewData) const override
    {
        m_Observable->notifyObservers(NewData);
    }

    void layEggs(unsigned int EggNum); //will be called by Nature

private:
    Observable *m_Observable;
};

class BlackChicken : public Subject
{
public:
    BlackChicken()
    : m_Observable(new Observable)
    {
    }

    virtual ~BlackChicken()
    {
        delete m_Observable;
    }

    virtual void registerObserver(Observer *const NewObserver) override
    {
        m_Observable->registerObserver(NewObserver);
    }

    virtual void removeObserver(Observer *const ObsoleteObserver) override
    {
        m_Observable->removeObserver(ObsoleteObserver);
    }

    virtual void notifyObservers(const Data &NewData) const override
    {
        m_Observable->notifyObservers(NewData);
    }

    void layEggs(unsigned int EggNum); //will be called by Nature

private:
    Observable *m_Observable;
};

#endif
