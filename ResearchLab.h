#ifndef RESEARCHLAB_H
#define RESEARCHLAB_H
#include <queue>
#include "Facility.h"
#include "Bank.h"
#include "Trap.h"
#include "ReclaimTrap.h"
#include "WoundTrap.h"

using namespace std;

// class Engine;

class ResearchLab : public Facility
{
public:
    mutex queueMutex;
    ResearchLab();
    Trap *produceTrap(char type);
    void finalize();
    void setToEngine();
    bool bankRequest(int val);
    int withdraw(int value);
    void deposit(int value);
    void trigger();
};

#endif // RESEARCHLAB_H
