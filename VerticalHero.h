#ifndef VERTICALHERO_H
#define VERTICALHERO_H
#include <string>
#include "Hero.h"
using namespace std;

class VerticalHero : public Hero
{
private:
public:
    // variables:
    // functions:
    VerticalHero();
    ~VerticalHero();
    void Search(Lair l,int index);
};

#endif // VERTICALHERO_H