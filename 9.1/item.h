#ifndef _CONCRETE_ITEM_H_
#define _CONCRETE_ITEM_H_

#include <string>

class MenuItem
{
public:
    MenuItem(const std::string &Name)
    : m_FoodName(Name)
    {
    }

    std::string getFoodName() const
    {
        return m_FoodName;
    }

private:
    std::string m_FoodName;
};

bool operator<(const MenuItem &Item1, const MenuItem &Item2);

#endif
