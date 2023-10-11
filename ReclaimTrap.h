#include "Hero.h"
#include "Trap.h"

#ifndef RECLAIMTRAP_H
#define RECLAIMTRAP_H


class ReclaimTrap: public Trap{
public:
    int returnValue;
    //char Trt;
    ReclaimTrap();
    ~ReclaimTrap();
    int Reclaim(int w);
    int ex(int w);
};


#endif //RECLAIMTRAP_H
