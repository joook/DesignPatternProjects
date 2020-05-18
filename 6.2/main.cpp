#include <iostream>
#include <memory>
#include "receiver.h"
#include "command.h"
#include "invoker.h"

using namespace std;

//simulate a client
int main()
{
    ItalianFoodChef Chef1;
    ChineseFoodChef Chef2;
    Waiter Waiter1;
    shared_ptr<Command> Order1(make_shared<OrderCommand>(&Chef1, "pasta"));
    shared_ptr<Command> Order2(make_shared<OrderCommand>(&Chef2, "fried rice with egg"));

    Waiter1.setCommand(Order1);
    Waiter1.setCommand(Order2);
    Waiter1.orderUp();

    return 0;
}

