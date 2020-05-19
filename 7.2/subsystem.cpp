#include "subsystem.h"
#include <iostream>

using namespace std;

void Amplifier::on()
{
    cout << "Amplifier on." << endl;
}

void Amplifier::off()
{
    cout << "Amplifier off." << endl;
}

void Amplifier::setVolume(const unsigned int Volumn)
{
    cout << "Amplifier setting volume to " << Volumn << "." << endl;
}

void DvdPlayer::on()
{
    cout << "DvdPlayer on." << endl;
}

void DvdPlayer::off()
{
    cout << "DvdPlayer off." << endl;
}

void DvdPlayer::play(const string &Movie)
{
    cout << "DvdPlayer playing \"" << Movie << "\"." << endl;
}

void Screen::on()
{
    cout << "Screen on." << endl;
}

void Screen::off()
{
    cout << "Screen off." << endl;
}

