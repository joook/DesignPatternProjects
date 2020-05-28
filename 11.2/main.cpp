#include "subject.h"
#include "real_subject.h"
#include "proxy.h"
#include <iostream>

using namespace std;

int main()
{
    shared_ptr<RealBlog> BlogPtr = make_shared<RealBlog>();
    BlogOwnerProxy Role1(BlogPtr);
    BlogGuestProxy Role2(BlogPtr);

    cout << "[Owner]" << endl;
    Role1.read();
    Role1.write();

    cout << "[Guest]" << endl;
    Role2.read();
    Role2.write();

    return 0;
}

