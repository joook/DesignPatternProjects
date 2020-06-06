#include "command.h"
#include "receiver.h"

using namespace std;

void DinnerCommand::execute() const
{
    if(m_ItalianFoodChef)
    {
        m_ItalianFoodChef->prepareIngredients(m_DishName);
        m_ItalianFoodChef->makeDishes(m_DishName);
    }
    else
    {
    }
}

void DrinkCommand::execute() const
{
    if(m_Bartender)
    {
        m_Bartender->prepareIngredients();
        m_Bartender->makeCocktail();
    }
    else
    {
    }
}
