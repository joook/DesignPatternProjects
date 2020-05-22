#include "item.h"

bool operator<(const MenuItem &Item1, const MenuItem &Item2)
{
    return Item1.getFoodName() < Item2.getFoodName();
}

