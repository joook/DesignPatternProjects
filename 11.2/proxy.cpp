#include <iostream>
#include "proxy.h"
#include "real_subject.h"

using namespace std;

void BlogOwnerProxy::read()
{
    if(m_RealBlogPtr)
    {
        m_RealBlogPtr->read();
    }
    else
    {
        cout << "Oops, the blog doesn't exist." << endl;
    }
}

void BlogOwnerProxy::write()
{
    if(m_RealBlogPtr)
    {
        m_RealBlogPtr->write();
    }
    else
    {
        cout << "Oops, the blog doesn't exist." << endl;
    }
}

void BlogGuestProxy::read()
{
    if(m_RealBlogPtr)
    {
        m_RealBlogPtr->read();
    }
    else
    {
        cout << "Oops, the blog doesn't exist." << endl;
    }
}

void BlogGuestProxy::write()
{
    cout << "You are not the owner of the blog, write action denied." << endl;
}

