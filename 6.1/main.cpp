#include <iostream>
#include <memory>
#include "receiver.h"
#include "command.h"
#include "invoker.h"

using namespace std;

//simulate a client
int main()
{
    shared_ptr<Chef> Chef1(new ItalianFoodChef);
    shared_ptr<Chef> Chef2(new ChineseFoodChef);
    Waiter Waiter1;
    shared_ptr<Command> Order1(new OrderCommand(Chef1));
    shared_ptr<Command> Order2(new OrderCommand(Chef2));

    Waiter1.setCommand(Order1);
    Waiter1.setCommand(Order2);
    Waiter1.orderUp();

    return 0;
}

