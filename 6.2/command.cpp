#include "command.h"
#include "receiver.h"

using namespace std;

void OrderCommand::execute() const
{
    if(m_Chef)
    {
        m_Chef->prepareIngredients(m_Name);
        m_Chef->makeDishes(m_Name);
    }
    else
    {
    }
}
