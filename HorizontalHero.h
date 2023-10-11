#ifndef HORIZONTAL_HERO_H
#define HORIZONTAL_HERO_H
#include <string>
#include "Hero.h"
#include "Lair.h"
using namespace std;

class HorizontalHero : public Hero
{
private:
public:
    // variables:
    Lair *myLair;
    // functions:
    HorizontalHero();
    HorizontalHero(Lair *l);
    ~HorizontalHero();
    void Search(Lair *l, int index);
};

#endif