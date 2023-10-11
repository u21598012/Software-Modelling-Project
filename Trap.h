#ifndef TRAP_H
#define TRAP_H
// #include "Lair.h"
//#include "tile.h"
// #include "VerticalHero.h"
using namespace std;

class Trap
{
public:
    int xc;
    int yc;
    bool intruder;
    char Trt;
    Trap();
    Trap(int x, int y);
    ~Trap();
    // void insertTrap(Trap* t, Lair* l);
    void setX(int x);
    void setY(int y);
    virtual int ex(int value) = 0;
};

#endif
