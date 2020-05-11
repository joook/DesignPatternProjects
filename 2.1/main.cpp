#include "weather_station.h"
#include "subject.h"
#include "observer.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//simulate A WeatherStation
int main()
{
    WeatherStation Station;
    WeatherSubject Sub;
    Observer *ObsPtr1 = new CurrentConditionDisplay();
    Observer *ObsPtr2 = new StatisticsDisplay();

    Sub.registerObserver(ObsPtr1);
    Sub.registerObserver(ObsPtr2);

    while(true)
    {
        this_thread::sleep_for(chrono::seconds(5));

        //get weather data once in a while
        float T = Station.getTemperature();
        float H = Station.getHumidity();
        float P = Station.getPressure();

        //update the billboards
        Sub.setMeasurements(T, H, P);
    }

    delete ObsPtr1;
    delete ObsPtr2;

    return 0;
}

