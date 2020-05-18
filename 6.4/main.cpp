#include <iostream>
#include <memory>
#include "receiver.h"
#include "command.h"
#include "invoker.h"

using namespace std;

int main()
{
    Text Text1;
    Editor Editor1;

    shared_ptr<Command> PasteCommand1 = make_shared<PasteCommand>(&Text1);

    Editor1.setCommand(PasteCommand1);
    Editor1.undo();
    Editor1.redo();

    return 0;
}



