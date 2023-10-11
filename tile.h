#ifndef TILE_H
#define TILE_H
#include "Trap.h"
#include <string>
#include <iostream>
using namespace std;

class tile
{
private:
public:
    // variables:
    tile *up;
    tile *down;
    tile *left;
    tile *right;
    int x;
    int y;
    int Balance; // remove this as other classes are created
    Trap *trap;
    bool hasHero;
    char trapT;
    // functions:
    tile();
    tile(int x, int y);
    ~tile();
    void location();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void setTB(int tb);
    int getTB();
    void addTrap(Trap *t);
    void removeTrap(Trap *t);
    void spring();
};

#endif // TILE_H