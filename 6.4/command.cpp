#include "command.h"
#include "receiver.h"

using namespace std;

void PasteCommand::execute() const
{
    if(m_Text)
    {
        m_Text->paste();
    }
    else
    {
    }
}

void PasteCommand::undo() const
{
    if(m_Text)
    {
        m_Text->cut();
    }
    else
    {
    }
}
