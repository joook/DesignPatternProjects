#ifndef _RECEIVER_H_
#define _RECEIVER_H_

class Chef
{
public:
    virtual ~Chef() = default;

public:
    virtual void prepareIngredients() const = 0;
    virtual void makeDishes() const = 0;
};

class ItalianFoodChef : public Chef
{
public:
    virtual void prepareIngredients() const override;
    virtual void makeDishes() const override;
};

class ChineseFoodChef : public Chef
{
public:
    virtual void prepareIngredients() const override;
    virtual void makeDishes() const override;
};

#endif
