#ifndef _DATA_H_
#define _DATA_H_

#include <string>

class Data
{
public:
    Data(const std::string &EggType, unsigned int EggNum = 0)
    : m_EggType(EggType)
    , m_EggNum(EggNum)
    {
    }

public:
    std::string m_EggType;
    unsigned int m_EggNum;
};

#endif
