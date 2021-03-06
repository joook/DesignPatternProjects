#include <iostream>
#include "item.h"
#include "iterator.h"
#include "aggregate.h"

using namespace std;

void printMenu(const shared_ptr<Menu> &MenuPtr)
{
    cout << "[Menu]" << endl;
    shared_ptr<Iterator> ItrPtr = MenuPtr->createIterator();
    while(ItrPtr->hasNext())
    {
        cout << ItrPtr->next()->getFoodName() << endl;
    }
}

int main()
{
    DinerMenu Menu1;
    Menu1.add(MenuItem("Pizza"));
    Menu1.add(MenuItem("Bacon"));
    Menu1.add(MenuItem("Salad"));

    BreakfastMenu Menu2;
    Menu2.add(MenuItem("Pancake"));
    Menu2.add(MenuItem("Waffle"));
    Menu2.add(MenuItem("Milk"));

    printMenu(shared_ptr<Menu>(new DinerMenu(Menu1)));
    printMenu(shared_ptr<Menu>(new BreakfastMenu(Menu2)));

    return 0;
}

