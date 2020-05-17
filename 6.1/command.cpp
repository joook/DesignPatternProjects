#include "command.h"
#include "receiver.h"

using namespace std;

void OrderCommand::execute() const
{
    if(m_Chef)
    {
        m_Chef->prepareIngredients();
        m_Chef->makeDishes();
    }
    else
    {
    }
}
