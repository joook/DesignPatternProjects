#include "abstract_class.h"
#include "concrete_class.h"
#include <iostream>

using namespace std;

int main()
{
    Tea Tea1;
    Coffee Coffee1;

    cout << "Making tea..." << endl;
    Tea1.prepareRecipe();
    cout << "Making coffee..." << endl;
    Coffee1.prepareRecipe();

    return 0;
}
