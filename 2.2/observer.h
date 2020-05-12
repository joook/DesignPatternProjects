#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <vector>

float getMinVal(const std::vector<float> &DataList);
float getMaxVal(const std::vector<float> &DataList);
float getAvgVal(const std::vector<float> &DataList);

class Subject;
class Data;

class Observer
{
public:
    Observer() = default;
    virtual void update(const Subject *const SubPtr) = 0;
};

class WeatherObserver : public Observer
{
public:
    WeatherObserver() = default;
    virtual void display() const = 0;
};

class CurrentConditionDisplay : public WeatherObserver
{
public:
    CurrentConditionDisplay() = default;
    virtual void update(const Subject *const SubPtr) override;
    virtual void display() const override;

private:
    float m_CurrentTemperature = 0.0;
    float m_CurrentHumidity = 0.0;
    float m_CurrentPressure = 0.0;
};

class StatisticsDisplay : public WeatherObserver
{
public:
    StatisticsDisplay() = default;
    virtual void update(const Subject *const SubPtr) override;
    virtual void display() const override;

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

private:
    std::vector<float> m_TemperatureList;
    std::vector<float> m_HumidityList;
    std::vector<float> m_PressureList;
};

#endif
