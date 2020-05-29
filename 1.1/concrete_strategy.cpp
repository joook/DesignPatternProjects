#include "concrete_strategy.h"
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

void Quack::quack() const
{
    cout << "I'm quacking..." << endl;
}

void Squeak::quack() const
{
    cout << "I'm squeaking..." << endl;
}

void MuteQuack::quack() const
{
    cout << "I cannot quack..." << endl;
}

