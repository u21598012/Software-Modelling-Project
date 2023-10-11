#include "tile.h"
#include <string>
#include <vector>
using namespace std;

tile::tile()
{
    Balance = 100;
    left = NULL;
    right = NULL;
    up = NULL;
    down = NULL;

    this->x = 0;
    this->y = 0;
    this->trapT = 'x';
    // trap = NULL;
}

tile::tile(int x, int y)
{
    left = NULL;
    right = NULL;
    up = NULL;
    down = NULL;

    this->x = x;
    this->y = y;
}

tile::~tile()
{
    delete left;
    delete right;
    delete up;
    delete down;
}

void tile::location()
{
    cout << "x : ";
    cout << this->x;
    cout << " y : ";
    cout << this->y;
    cout << " ";
}

void tile::setX(int x)
{
    this->x = x;
}

void tile::setY(int y)
{
    this->y = y;
}

int tile::getX()
{
    return this->x;
}

int tile::getY()
{
    return this->y;
}

void tile::setTB(int tb)
{
    this->Balance = tb;
}

int tile::getTB()
{
    return this->Balance;
}

void tile::addTrap(Trap *t)
{
    this->trapT = t->Trt;
    this->trap = t;
}

void tile::removeTrap(Trap *t)
{
    this->trap = NULL;
}

void tile::spring()
{
    // if (this->hasHero == true)
    // {
    //     this->trap->ex(this->hero);
    // }
}