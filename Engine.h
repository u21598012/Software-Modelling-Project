#ifndef ENGINE_H
#define ENGINE_H
#include "Facility.h"
// #include "Bank.h"
// #include "ResearchLab.h"
#include <string>
#include <queue>
using namespace std;

// class Bank;
// class ResearchLab;
class Facility;
class Engine
{
private:
public:
    // variables:

    // functions:
    Facility *rl;
    Facility *b;
    // queue<Facility *> colleagues;
    Engine();
    Engine(Facility *lab, Facility *bank);
    ~Engine();
    bool processRequest(int val);
    void start();
};

#endif // ENGINE_H