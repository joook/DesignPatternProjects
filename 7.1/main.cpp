#include "adaptee.h"
#include "target.h"
#include "adapter.h"

int main()
{
    GreenHeadDuck Duck1;
    RedChicken Chicken1;
    ChickenAdapter FakeDuck2(&Chicken1);

    Duck1.fly();
    Duck1.quack();
    FakeDuck2.fly();
    FakeDuck2.quack();

    return 0;
}

