#ifndef _FACADE_H_
#define _FACADE_H_

#include <string>

class Amplifier;
class DvdPlayer;
class Screen;

class HomeTheater //did not consider about copy control
{
public:
    HomeTheater(Amplifier * const SomeAmplifier, DvdPlayer * const SomeDvdPlayer, Screen * const SomeScreen)
    : m_Amplifier(SomeAmplifier)
    , m_DvdPlayer(SomeDvdPlayer)
    , m_Screen(SomeScreen)
    {
    }

    void watchMovie(const std::string &Movie);

private:
    Amplifier *m_Amplifier;
    DvdPlayer *m_DvdPlayer;
    Screen *m_Screen;
};

#endif
