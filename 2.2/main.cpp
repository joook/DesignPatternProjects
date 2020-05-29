#include "subject.h"
#include "observer.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

float getTemperature()
{
    static float T = 20.0; //Centigrade
    if(T < 25)
    {
        T += 1.3;
    }
    else if(T >= 25 && T < 30)
    {
        T += 1.2;
    }
    else
    {
        T = 20;
    }
    return T;
}

float getHumidity()
{
    static float H = 30.0; //%
    if(H > 55)
    {
        H -= 2.1;
    }
    else if(H <= 55 && H > 30)
    {
        H -= 1.7;
    }
    else
    {
        H += 40;
    }
    return H;
}

float getPressure()
{
    static float P = 1000.0; //hPa
    if(P > 1010)
    {
        P = 1000;
    }
    else
    {
        P += 0.3;
    }
    return P;
}

//simulate a weather station sending weather data to the display devices
int main()
{
    WeatherSubject Sub;
    Observer *ObsPtr1 = new CurrentConditionDisplay();
    Observer *ObsPtr2 = new StatisticsDisplay();

    Sub.registerObserver(ObsPtr1);
    Sub.registerObserver(ObsPtr2);

    while(true)
    {
        this_thread::sleep_for(chrono::seconds(5));

        //get weather data once in a while
        float T = getTemperature();
        float H = getHumidity();
        float P = getPressure();

        //update the billboards
        Sub.setMeasurements(T, H, P);
    }

    delete ObsPtr1;
    delete ObsPtr2;

    return 0;
}

