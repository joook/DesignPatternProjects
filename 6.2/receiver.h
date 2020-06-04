#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <string>

class Chef
{
public:
    virtual ~Chef() = default;

public:
    virtual void prepareIngredients(const std::string &Name) const = 0;
    virtual void makeDishes(const std::string &Name) const = 0;
};

class ItalianFoodChef : public Chef
{
public:
    virtual void prepareIngredients(const std::string &Name) const override;
    virtual void makeDishes(const std::string &Name) const override;
};

class ChineseFoodChef : public Chef
{
public:
    virtual void prepareIngredients(const std::string &Name) const override;
    virtual void makeDishes(const std::string &Name) const override;
};

#endif
