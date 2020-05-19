#ifndef _SUBSYSTEM_H_
#define _SUBSYSTEM_H_

#include <string>

class Amplifier
{
public:
    void on();
    void off();
    void setVolume(const unsigned int Volumn);
};

class DvdPlayer
{
public:
    void on();
    void off();
    void play(const std::string &Movie);
};

class Screen
{
public:
    void on();
    void off();
};

#endif
