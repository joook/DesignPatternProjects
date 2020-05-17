#include "receiver.h"
#include <iostream>

using namespace std;

void ItalianFoodChef::prepareIngredients() const
{
    cout << "[Italian Chef Preparing For You: Pasta]" << endl;
    cout << "Get pasta." << endl;
    cout << "Get sauce." << endl;
}

void ItalianFoodChef::makeDishes() const
{
    cout << "Boil water." << endl;
    cout << "Add pasta." << endl;
    cout << "Drain the pasta." << endl;
    cout << "Add sauce." << endl;
}

void ChineseFoodChef::prepareIngredients() const
{
    cout << "[Chinese Chef Preparing For You: Fried Rice with Egg]" << endl;
    cout << "Get cooked rice." << endl;
    cout << "Get eggs." << endl;
    cout << "Get oil." << endl;
}

void ChineseFoodChef::makeDishes() const
{
    cout << "Beat eggs together." << endl;
    cout << "Heat oil." << endl;
    cout << "Add rice." << endl;
    cout << "Stir rice." << endl;
    cout << "Move out rice." << endl;
    cout << "Add oil and eggs." << endl;
    cout << "Stir eggs." << endl;
    cout << "Mix in with the rice." << endl;
    cout << "Stir mixture." << endl;
}

