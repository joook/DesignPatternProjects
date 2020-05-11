#include "weather_station.h"

using namespace std;

float WeatherStation::getTemperature()
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

float WeatherStation::getHumidity()
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

float WeatherStation::getPressure()
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

