#include "observer.h"
#include "subject.h"
#include "data.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

float getMinVal(const vector<float> &DataList)
{
    size_t Size = DataList.size();
    if(Size != 0)
    {
        return *min_element(DataList.cbegin(), DataList.cend());
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
        return *max_element(DataList.cbegin(), DataList.cend());
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
        float Sum = accumulate(DataList.cbegin(), DataList.cend(), 0.0);
        float Avg = Sum/Size;
        return Avg;
    }
    else
    {
        return 0.0;
    }
}

void CurrentConditionDisplay::update(const Subject *const SubPtr)
{
    if(SubPtr != nullptr)
    {
        Data NewData = SubPtr->getData();
        m_CurrentTemperature = NewData.m_Temperature;
        m_CurrentHumidity = NewData.m_Humidity;
        m_CurrentPressure = NewData.m_Pressure;

        //display the billboard after update
        display();
    }
    else
    {
    }
}

void CurrentConditionDisplay::display() const
{
    cout << "-----CurrentConditionDisplay-----" << endl;
    cout << "Current temperature: " << m_CurrentTemperature << endl;
    cout << "Current humidity: " << m_CurrentHumidity << endl;
    cout << "Current pressure: " << m_CurrentPressure << endl;
    cout << endl;
}

void StatisticsDisplay::update(const Subject *const SubPtr)
{
    if(SubPtr != nullptr)
    {
        Data NewData = SubPtr->getData();
        m_TemperatureList.push_back(NewData.m_Temperature);
        m_HumidityList.push_back(NewData.m_Humidity);
        m_PressureList.push_back(NewData.m_Pressure);

        //display the billboard after update
        display();
    }
    else
    {
    }
}

void StatisticsDisplay::display() const
{
    cout << "-----StatisticsDisplay-----" << endl;
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

