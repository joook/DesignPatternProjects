#include "concrete_class.h"
#include <iostream>

using namespace std;

void Tea::brew()
{
    cout << "Steeping the tea." << endl;
}

void Tea::addCondiments()
{
    cout << "Adding lemon." << endl;
}

void Coffee::brew()
{
    cout << "Dripping coffee through filter." << endl;
}

void Coffee::addCondiments()
{
    cout << "Adding suger and milk." << endl;
}

bool Coffee::customerWantsCondiments()
{
    if(getCustomerInput() == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char Coffee::getCustomerInput()
{
    char Answer;
    cout << "Would you like milk and suger with your coffee (y/n)?" << endl;
    cin >> Answer;
    return Answer;
}

