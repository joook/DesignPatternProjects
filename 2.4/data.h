#ifndef _DATA_H_
#define _DATA_H_

class Data
{
public:
    Data(float t = 0.0, float h = 0.0, float p = 0.0)
    : m_Temperature(t)
    , m_Humidity(h)
    , m_Pressure(p)
    {
    }

public:
    float m_Temperature;
    float m_Humidity;
    float m_Pressure;
};

#endif
