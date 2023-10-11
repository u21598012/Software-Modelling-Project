#ifndef WOUNDTRAP_H
#define WOUNDTRAP_H
#include "Trap.h"
#include "Hero.h"
using namespace std;

class WoundTrap : public Trap
{
public:
    WoundTrap();
    ~WoundTrap();
    int Wound(int w);
    int ex(int w);
};

#endif // WOUNDTRAP_H
