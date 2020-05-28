#include <iostream>
#include <fstream>
#include <sstream>
#include "real_subject.h"

using namespace std;

RealImage::RealImage(const string &FileName)
: m_ImageDataPtr(make_shared<vector<string>>())
{
    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Line;
        while(getline(FileStream, Line))
        {
            m_ImageDataPtr->push_back(Line);
        }
        FileStream.close();
    }
    else
    {
        cout << "Can not open file." << endl;
    }
}

void RealImage::paint()
{
    for(auto Itr = m_ImageDataPtr->begin(); Itr != m_ImageDataPtr->cend(); Itr++)
    {
        cout << *Itr << endl;
    }
}

