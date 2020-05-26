#include <iostream>
#include "context.h"
#include "state.h"

using namespace std;

int main()
{
    GumballMachine Machine1;
    GumballMachine Machine2;

    cout << "Gumball machine test start: " << endl;

    Machine2.fill(1);

    Machine1.insertQuarter();
    Machine1.turnCrank();
    Machine1.fill(1);
    Machine1.insertQuarter();
    Machine1.turnCrank();

    Machine2.insertQuarter();
    Machine2.turnCrank();
    Machine2.insertQuarter();
    Machine2.turnCrank();

    return 0;
}
