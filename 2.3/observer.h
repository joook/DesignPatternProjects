#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <vector>

class Data;

class Observer
{
public:
    Observer() = default;
    virtual ~Observer() = default;

public:
    virtual void update(const Data &NewData) = 0;
};

class Farmer : public Observer
{
public:
    Farmer() = default;

public:
    virtual void update(const Data &NewData) override;
    virtual void display() const;

private:
    unsigned int m_TotalEggNum = 0;
};

#endif
