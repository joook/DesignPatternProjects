#include "receiver.h"
#include <iostream>
#include <string>

using namespace std;

void ItalianFoodChef::prepareIngredients(const string &Name) const
{
    cout << "[Italian Chef]" << endl;
    if(Name == "pasta")
    {
        cout << "Preparing pasta." << endl;
    }
    else
    {
        cout << "Preparing pizza." << endl;
    }
}

void ItalianFoodChef::makeDishes(const string &Name) const
{
    if(Name == "pasta")
    {
        cout << "Pasta done." << endl;
    }
    else
    {
        cout << "Pizza done." << endl;
    }
}

void ChineseFoodChef::prepareIngredients(const string &Name) const
{
    cout << "[Chinese Chef]" << endl;
    if(Name == "fried rice with egg")
    {
        cout << "Preparing fried rice with egg." << endl;
    }
    else
    {
        cout << "Preparing Kung Pao chicken." << endl;
    }
}

void ChineseFoodChef::makeDishes(const string &Name) const
{
    if(Name == "fried rice with egg")
    {
        cout << "Fried rice with egg done." << endl;
    }
    else
    {
        cout << "Kung Pao chicken done." << endl;
    }
}

