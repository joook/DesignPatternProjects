#include "subsystem.h"
#include "facade.h"

using namespace std;

int main()
{
    Amplifier Amplifier1;
    DvdPlayer DvdPlayer1;
    Screen Screen1;
    HomeTheater HomeTheater1(&Amplifier1, &DvdPlayer1, &Screen1);

    HomeTheater1.watchMovie("WALL.E");

    return 0;
}

