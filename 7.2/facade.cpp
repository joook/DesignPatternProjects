#include "facade.h"
#include "subsystem.h"
#include <iostream>

using namespace std;

void HomeTheater::watchMovie(const string &Movie)
{
    if(m_Amplifier && m_DvdPlayer && m_Screen)
    {
        m_Amplifier->on();
        m_Amplifier->setVolume(5);
        m_Screen->on();
        m_DvdPlayer->on();
        m_DvdPlayer->play(Movie);
    }
    else
    {
        cout << "Device error." << endl;
    }
}
