#include "subject.h"
#include "observer.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

unsigned int getRandomNum()
{
    int Rand = rand() % 5 + 1;
    return static_cast<unsigned int>(Rand);
}

//simulate mother nature having chickens lay eggs
int main()
{
    RedChicken Chicken1;
    GreyChicken Chicken2;
    BlackChicken Chicken3;
    Observer *FarmerPtr = new Farmer();

    Chicken1.registerObserver(FarmerPtr);
    Chicken2.registerObserver(FarmerPtr);
    Chicken3.registerObserver(FarmerPtr);

    while(true)
    {
        //lay eggs once in a while
        Chicken1.layEggs(getRandomNum());
        this_thread::sleep_for(chrono::seconds(3));

        Chicken2.layEggs(getRandomNum());
        this_thread::sleep_for(chrono::seconds(3));

        Chicken3.layEggs(getRandomNum());
        this_thread::sleep_for(chrono::seconds(3));
    }

    delete FarmerPtr;

    return 0;
}

