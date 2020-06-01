#include "observer.h"
#include "subject.h"
#include "data.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void Farmer::update(const Data &NewData)
{
    cout << NewData.m_EggNum << " more ";
    cout << NewData.m_EggType << (NewData.m_EggNum > 1 ? "s" : "");
    cout <<  (NewData.m_EggNum == 5 ? "!" : ".") << endl;

    m_TotalEggNum += NewData.m_EggNum;

    //display the billboard after update
    display();
}

void Farmer::display() const
{
    cout << "Now the total number of eggs is: " << m_TotalEggNum << endl;
}

