#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint> // std::uint32_t

enum class EventId : std::uint32_t
{
    INSERT_QUARTER = 0,
    EJECT_QUARTER = 1,
    TURN_CRANK = 2,
    FILL = 3,
};

enum class StateId : std::uint32_t
{
    SOLD_OUT_STATE = 0,
    NO_QUARTER_STATE = 1,
    HAS_QUARTER_STATE = 2,
};


#endif
