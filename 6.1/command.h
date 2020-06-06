#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <string>

class ItalianFoodChef;
class Bartender;

class Command
{
public:
    virtual ~Command() = default;

public:
    virtual void execute() const = 0;
};

class DinnerCommand : public Command //did not consider about copy control
{
public:
    DinnerCommand(ItalianFoodChef * const SomeChef, const std::string &DishName)
    : m_ItalianFoodChef(SomeChef)
    , m_DishName(DishName)
    {
    }

public:
    virtual void execute() const override;

protected:
    ItalianFoodChef *m_ItalianFoodChef;
    std::string m_DishName;
};

class DrinkCommand : public Command //did not consider about copy control
{
public:
    DrinkCommand(Bartender * const SomeBartender)
    : m_Bartender(SomeBartender)
    {
    }

public:
    virtual void execute() const override;

protected:
    Bartender *m_Bartender;
};

#endif
