#ifndef LAIR_H
#define LAIR_H
#include <string>
#include "tile.h"
#include "Trap.h"
// #include "emptyLair.h"
using namespace std;

class Lair
{
private:
public:
    // variables:
    tile *zeroZero;
    int xp;
    int yp;
    // functions:
    Lair();
    ~Lair();
    void add(tile *t);
    // void remove(int x, int y);
    void print();
    tile *getTile(int x, int y);
    void placeTrap(int x, int y, Trap *t);
    int calculateTotalBalance();
};

#endif // LAIR_H