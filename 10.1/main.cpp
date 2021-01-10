#include <iostream>
#include "context.h"

int main()
{
    GumballMachine Machine1("Machine1");
    GumballMachine Machine2("Machine2");

    std::cout << "==========Gumball machine test start==========" << std::endl;

    std::cout << "[Fill 20 gumballs into Machine2.]" << std::endl;
    Machine2.fill(20);
    std::cout << std::endl;

    std::cout << "[Fill 1 gumball into Machine1.]" << std::endl;
    Machine1.fill(1);
    std::cout << "[Insert 1 quarter into Machine1.]" << std::endl;
    Machine1.insertQuarter();
    std::cout << "[Turn crank on Machine1.]" << std::endl;
    Machine1.turnCrank();
    std::cout << "[Insert 1 quarter into Machine1.]" << std::endl;
    Machine1.insertQuarter();
    std::cout << "[Turn crank on Machine1.]" << std::endl;
    Machine1.turnCrank();
    std::cout << std::endl;

    std::cout << "[Insert 1 quarter into Machine2.]" << std::endl;
    Machine2.insertQuarter();
    std::cout << "[Turn crank on Machine2.]" << std::endl;
    Machine2.turnCrank();
    std::cout << "[Turn crank on Machine2.]" << std::endl;
    Machine2.turnCrank();

    return 0;
}
