#ifndef _TARGET_H_
#define _TARGET_H_

class Duck
{
public:
    virtual ~Duck() = default;

public:
    virtual void fly() = 0;
    virtual void quack() = 0;
};

class GreenHeadDuck : public Duck
{
public:
    virtual void fly() override;
    virtual void quack() override;
};

#endif

