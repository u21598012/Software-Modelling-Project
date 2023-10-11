#ifndef MENU_H
#define MENU_H
#include "Facility.h"
#include "ResearchLab.h"
#include "Bank.h"
#include "Lair.h"
#include "tile.h"
#include "Trap.h"
#include <string>
using namespace std;

class Menu {
private:

public:
//variables:
Bank* b;
ResearchLab *rl;
Lair *lair;
//functions:
    Menu();
    Menu(Bank *b, ResearchLab *rl, Lair *l);
    ~Menu();
    void addTrap(int x, int y, char type);
    void removeTrap(int x, int y);
    void start();
};

#endif // MENU_H