#include <iostream>
#include <memory>
#include "receiver.h"
#include "command.h"
#include "invoker.h"

using namespace std;

//simulate a client
int main()
{
    ItalianFoodChef Receiver1;
    Bartender Receiver2;
    Waiter Waiter1;
    shared_ptr<Command> Order1(make_shared<DinnerCommand>(&Receiver1, "pizza"));
    shared_ptr<Command> Order2(make_shared<DrinkCommand>(&Receiver2));

    Waiter1.setCommand(Order1);
    Waiter1.setCommand(Order2);
    Waiter1.orderUp();

    return 0;
}

