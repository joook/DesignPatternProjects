#ifndef _DATA_H_
#define _DATA_H_

class Data
{
public:
    Data(float T = 0.0, float H = 0.0, float P = 0.0)
    : m_Temperature(T)
    , m_Humidity(H)
    , m_Pressure(P)
    {
    }

public:
    float m_Temperature;
    float m_Humidity;
    float m_Pressure;
};

#endif
