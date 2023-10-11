#ifndef REVERSEHERO_H
#define REVERSEHERO_H
#include <string>
#include "Hero.h"
using namespace std;

class ReverseHero : public Hero
{
private:
public:
    // variables:
    // functions:
    ReverseHero();
    ~ReverseHero();
    void Search(Lair* l,int index);
};

#endif // VERTICALHERO_H