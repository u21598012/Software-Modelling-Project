#ifndef FACILITY_H
#define FACILITY_H
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include "Trap.h"
#include "Hero.h"
#include "Engine.h"

class Engine;
class Facility
{
public:
    int balance;
    Engine *e;
    queue<Trap *> productionQueue;
    queue<Trap *> RFU;
    Facility();
    ~Facility();
    virtual Trap *produceTrap(char type);
    // void attach();
    virtual void finalize() = 0;
    virtual void setToEngine() = 0;
    virtual bool bankRequest(int val) = 0;
    virtual int withdraw(int value) = 0;
    virtual void deposit(int value) = 0;
    // virtual void setToEngine() = 0;
};

#endif // FACILITY_H
