#include <iostream>
#include <chrono>
#include <thread>
#include "proxy.h"
#include "real_subject.h"

using namespace std;

void runLoadThread(ImageProxy *ImageProxyPtr)
{
    //cout << "Load thread id: " << std::this_thread::get_id() << endl;

    ImageProxyPtr->m_IsLoading = true;

    //pretend the thread is loading a very big image, costs 5s...
    std::this_thread::sleep_for(std::chrono::seconds(5));
    ImageProxyPtr->m_RealImagePtr = make_shared<RealImage>(ImageProxyPtr->m_ImagePath);

    ImageProxyPtr->m_IsLoading = false;
}

void ImageProxy::paint()
{
    if(m_RealImagePtr)
    {
        m_RealImagePtr->paint();
    }
    else
    {
        cout << "Loading [" << m_ImageName << "], please wait..." << endl;
        if(m_IsLoading == true)
        {
        }
        else
        {
            thread LoadThread(runLoadThread, this);
            LoadThread.detach();
        }
    }
}

