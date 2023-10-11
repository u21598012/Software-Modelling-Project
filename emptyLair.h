#ifndef EMPTYLAIR_H
#define EMPTYLAIR_H
#include <string>
#include "tile.h"
using namespace std;

class emptyLair
{
private:
public:
    // max layer has 4x4 titles
    //  variables:
    //  functions:
    emptyLair();
    ~emptyLair();
    virtual void add(tile *t) = 0;
    // virtual void remove(int x, int y) = 0;
};

#endif // EMPTYLAIR_H