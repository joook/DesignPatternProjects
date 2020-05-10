#include "fly_behavior.h"
#include <iostream>

using namespace std;

void FlyWithWings::fly() const
{
    cout << "I'm flying!" << endl;
}

void FlyNoWay::fly() const
{
    cout << "I cannot fly." << endl;
}

