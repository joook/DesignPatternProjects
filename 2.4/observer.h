#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <vector>

class Data;

class CurrentConditionDisplay
{
public:
    CurrentConditionDisplay() = default;
    ~CurrentConditionDisplay() = default;

public:
    void handle(const Data &data);
    void display() const;

private:
    float m_CurrentTemperature = 0.0;
    float m_CurrentHumidity = 0.0;
    float m_CurrentPressure = 0.0;
};

class StatisticsDisplay
{
public:
    StatisticsDisplay() = default;
    ~StatisticsDisplay() = default;

public:
    void handle(const Data &data);
    void display() const;

private:
    float getMinTemperature() const { return getMinVal(m_TemperatureList); }
    float getMaxTemperature() const { return getMaxVal(m_TemperatureList); }
    float getAvgTemperature() const { return getAvgVal(m_TemperatureList); }
    float getMinHumidity() const { return getMinVal(m_HumidityList); }
    float getMaxHumidity() const { return getMaxVal(m_HumidityList); }
    float getAvgHumidity() const { return getAvgVal(m_HumidityList); }
    float getMinPressure() const { return getMinVal(m_PressureList); }
    float getMaxPressure() const { return getMaxVal(m_PressureList); }
    float getAvgPressure() const { return getAvgVal(m_PressureList); }
    
    float getMinVal(const std::vector<float> &dataList) const;
    float getMaxVal(const std::vector<float> &dataList) const;
    float getAvgVal(const std::vector<float> &dataList) const;

private:
    std::vector<float> m_TemperatureList;
    std::vector<float> m_HumidityList;
    std::vector<float> m_PressureList;
};

#endif
