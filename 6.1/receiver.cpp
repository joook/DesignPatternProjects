#include "receiver.h"
#include <iostream>

using namespace std;

void ItalianFoodChef::prepareIngredients(const std::string &DishName) const
{
    cout << "[Italian Chef]" << endl;
    if(DishName == "pizza")
    {
        cout << "Preparing pizza ingredients." << endl;
    }
    else
    {
        cout << "Preparing pasta ingredients." << endl;
    }
}

void ItalianFoodChef::makeDishes(const std::string &DishName) const
{
    if(DishName == "pizza")
    {
        cout << "Pizza done." << endl;
    }
    else
    {
        cout << "Pasta done." << endl;
    }
}

void Bartender::prepareIngredients() const
{
    cout << "[Bartender]" << endl;
    cout << "Preparing cocktail ingredients." << endl;
}

void Bartender::makeCocktail() const
{
    cout << "Cocktail done." << endl;
}

