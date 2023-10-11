#include "ReclaimTrap.h"

ReclaimTrap::ReclaimTrap()
{
    this->returnValue = 0;
    this->Trt = 'r';
}

ReclaimTrap::~ReclaimTrap()
{
}

int ReclaimTrap::Reclaim(int w)
{
    bool rec = 0;
    if (intruder == true)
    {
        int att = w / 2;
        this->returnValue += att;
        return att;
    }
}

int ReclaimTrap::ex(int w)
{
    return Reclaim(w);
}
