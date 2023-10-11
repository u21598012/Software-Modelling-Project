#ifndef HERO_H
#define HERO_H
#include <string>
#include "tile.h"
// #include "emptyLair.h"
#include "Lair.h"
using namespace std;

class Hero
{
private:
public:
    // variables:
    int balance;
    int health;
    // functions:
    Hero();
    virtual ~Hero();
    virtual void Search(Lair *l, int index);
    int React(tile *t);
};

#endif // HERO_H