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

    std::string getFoodName()
    {
        return m_FoodName;
    }

private:
    std::string m_FoodName;
};

#endif
