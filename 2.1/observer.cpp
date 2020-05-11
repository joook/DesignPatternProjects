#include "observer.h"
#include "subject.h"
#include "data.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void CurrentConditionDisplay::update(const Data &NewData)
{
    if(m_Subject != nullptr)
    {
        m_CurrentTemperature = NewData.m_Temperature;
        m_CurrentHumidity = NewData.m_Humidity;
        m_CurrentPressure = NewData.m_Pressure;
    }
    else
    {
    }

    //display the billboard after update
    display();
}

void CurrentConditionDisplay::display() const
{
    cout << "[CurrentConditionDisplay]" << endl;
    cout << "Current temperature: " << m_CurrentTemperature << endl;
    cout << "Current humidity: " << m_CurrentHumidity << endl;
    cout << "Current pressure: " << m_CurrentPressure << endl;
    cout << endl;
}

float getMinVal(const vector<float> &DataList)
{
    size_t Size = DataList.size();
    if(Size != 0)
    {
        return *min_element(DataList.begin(), DataList.cend());
    }
    else
    {
        return 0.0;
    }
}

float getMaxVal(const vector<float> &DataList)
{
    size_t Size = DataList.size();
    if(Size != 0)
    {
        return *max_element(DataList.begin(), DataList.cend());
    }
    else
    {
        return 0.0;
    }
}

float getAvgVal(const vector<float> &DataList)
{
    size_t Size = DataList.size();
    if(Size != 0)
    {
        float Sum = accumulate(DataList.begin(), DataList.cend(), 0.0);
        float Avg = Sum/Size;
        return Avg;
    }
    else
    {
        return 0.0;
    }
}

void StatisticsDisplay::update(const Data &NewData)
{
    if(m_Subject != nullptr)
    {
        m_TemperatureList.push_back(NewData.m_Temperature);
        m_HumidityList.push_back(NewData.m_Humidity);
        m_PressureList.push_back(NewData.m_Pressure);
    }
    else
    {
    }

    //display the billboard after update
    display();
}

void StatisticsDisplay::display() const
{
    cout << "[StatisticsDisplay]" << endl;
    cout << "Min temperature: " << getMinTemperature() << endl;
    cout << "Max temperature: " << getMaxTemperature() << endl;
    cout << "Average temperature: " << getAvgTemperature() << endl;
    cout << "Min humidity: " << getMinHumidity() << endl;
    cout << "Max humidity: " << getMaxHumidity() << endl;
    cout << "Average humidity: " << getAvgHumidity() << endl;
    cout << "Min pressure: " << getMinPressure() << endl;
    cout << "Max pressure: " << getMaxPressure() << endl;
    cout << "Average pressure: " << getAvgPressure() << endl;
    cout << endl;
}

