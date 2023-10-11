#include "Trap.h"
#include "Lair.h"
#include "tile.h"
using namespace std;

Trap::Trap()
{
    this->xc = -1;
    this->yc = -1;
    this->intruder = false;
}

Trap::Trap(int x, int y)
{
    this->xc = x;
    this->yc = y;
}

Trap::~Trap()
{
}

// void Trap::insertTrap(Trap *t, Lair* l)
// {
//     tile* ptr = l->zeroZero;
//     int x=0;
//     int y=0;

//     while (x != this->xc)
//     {
//         ptr = ptr->right;
//     }

//     while (y != this->yc)
//     {
//         ptr = ptr->down;
//     }

//     //add function to add trap to tile
// }

void Trap::setX(int x)
{
    this->xc = x;
}

void Trap::setY(int y)
{
    this->yc = y;
}