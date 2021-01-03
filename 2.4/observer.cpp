#include "observer.h"
#include "subject.h"
#include "data.h"
#include <iostream>
#include <algorithm>
#include <numeric>

void CurrentConditionDisplay::handle(const Data &data)
{
    m_CurrentTemperature = data.m_Temperature;
    m_CurrentHumidity = data.m_Humidity;
    m_CurrentPressure = data.m_Pressure;

    //display the billboard after update
    display();
}

void CurrentConditionDisplay::display() const
{
    std::cout << "-----CurrentConditionDisplay-----" << std::endl;
    std::cout << "Current temperature: " << m_CurrentTemperature << std::endl;
    std::cout << "Current humidity: " << m_CurrentHumidity << std::endl;
    std::cout << "Current pressure: " << m_CurrentPressure << std::endl;
    std::cout << std::endl;
}

void StatisticsDisplay::handle(const Data &data)
{
    m_TemperatureList.push_back(data.m_Temperature);
    m_HumidityList.push_back(data.m_Humidity);
    m_PressureList.push_back(data.m_Pressure);

    //display the billboard after update
    display();
}

void StatisticsDisplay::display() const
{
    std::cout << "-----StatisticsDisplay-----" << std::endl;
    std::cout << "Min temperature: " << getMinTemperature() << std::endl;
    std::cout << "Max temperature: " << getMaxTemperature() << std::endl;
    std::cout << "Average temperature: " << getAvgTemperature() << std::endl;
    std::cout << "Min humidity: " << getMinHumidity() << std::endl;
    std::cout << "Max humidity: " << getMaxHumidity() << std::endl;
    std::cout << "Average humidity: " << getAvgHumidity() << std::endl;
    std::cout << "Min pressure: " << getMinPressure() << std::endl;
    std::cout << "Max pressure: " << getMaxPressure() << std::endl;
    std::cout << "Average pressure: " << getAvgPressure() << std::endl;
    std::cout << std::endl;
}

inline float StatisticsDisplay::getMinVal(const std::vector<float> &dataList) const
{
    std::size_t listSize = dataList.size();
    if(listSize != 0)
    {
        return *std::min_element(dataList.cbegin(), dataList.cend());
    }
    else
    {
        return 0.0;
    }
}

inline float StatisticsDisplay::getMaxVal(const std::vector<float> &dataList) const
{
    std::size_t listSize = dataList.size();
    if(listSize != 0)
    {
        return *std::max_element(dataList.cbegin(), dataList.cend());
    }
    else
    {
        return 0.0;
    }
}

inline float StatisticsDisplay::getAvgVal(const std::vector<float> &dataList) const
{
    std::size_t listSize = dataList.size();
    if(listSize != 0)
    {
        float sum = std::accumulate(dataList.cbegin(), dataList.cend(), 0.0);
        float avg = sum/listSize;
        return avg;
    }
    else
    {
        return 0.0;
    }
}
