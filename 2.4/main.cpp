#include "subject.h"
#include "observer.h"
#include <iostream>
#include <thread>
#include <chrono>

float getTemperature()
{
    static float t = 20.0; // Centigrade
    if(t < 25)
    {
        t += 1.3;
    }
    else if(t >= 25 && t < 30)
    {
        t += 1.2;
    }
    else
    {
        t = 20;
    }
    return t;
}

float getHumidity()
{
    static float h = 30.0; // %
    if(h > 55)
    {
        h -= 2.1;
    }
    else if(h <= 55 && h > 30)
    {
        h -= 1.7;
    }
    else
    {
        h += 40;
    }
    return h;
}

float getPressure()
{
    static float p = 1000.0; // hPa
    if(p > 1010)
    {
        p = 1000;
    }
    else
    {
        p += 0.3;
    }
    return p;
}

// simulate a weather station sending weather data to the display devices
int main()
{
    WeatherSubject subject{};
    CurrentConditionDisplay observer1{};
    StatisticsDisplay observer2{};

    subject.addHandler(std::bind(&CurrentConditionDisplay::handle, observer1, std::placeholders::_1));
    subject.addHandler(std::bind(&StatisticsDisplay::handle, observer2, std::placeholders::_1));

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // get weather data once in a while
        float t = getTemperature();
        float h = getHumidity();
        float p = getPressure();

        // update the billboards
        subject.setMeasurements(t, h, p);
    }

    return 0;
}

