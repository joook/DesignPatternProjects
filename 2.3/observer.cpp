#include "observer.h"
#include "subject.h"
#include "data.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void Farmer::update(const Data &NewData)
{
    m_TotalEggNum += NewData.m_EggNum;

    //display the billboard after update
    display();
}

void Farmer::display() const
{
    cout << "Now the total number of eggs is: " << m_TotalEggNum << endl;
}

