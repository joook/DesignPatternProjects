#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <string>

class Receiver
{
public:
    virtual ~Receiver() = default;
};

class ItalianFoodChef : public Receiver
{
public:
    virtual void prepareIngredients(const std::string &DishName) const;
    virtual void makeDishes(const std::string &DishName) const;
};

class Bartender : public Receiver
{
public:
    virtual void prepareIngredients() const;
    virtual void makeCocktail() const;
};

#endif
