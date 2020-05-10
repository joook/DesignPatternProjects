#include "quack_behavior.h"
#include <iostream>

using namespace std;

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
