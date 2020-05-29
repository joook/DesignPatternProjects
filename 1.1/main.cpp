#include "context.h"
#include "strategy.h"
#include "concrete_strategy.h"

using namespace std;

int main()
{
    const RedHeadDuck Duck1;
    const RubberDuck Duck2;

    Duck1.display();
    Duck1.swim();
    Duck1.performFly();
    Duck1.performQuack();

    Duck2.display();
    Duck2.swim();
    Duck2.performFly();
    Duck2.performQuack();

    return 0;
}

