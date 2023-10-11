#include "VerticalHero.h"
#include <string>
#include <vector>
using namespace std;

VerticalHero::VerticalHero():Hero()
{

}

void VerticalHero::Search(Lair l,int index)
{
    int xp = 0;
    tile *curr = l.zeroZero;
    while(xp != index)
    {
        curr = l.zeroZero->right;
    }
    while (curr != NULL)
    {
        balance += curr->getTB();
        curr = curr->down;
    }
}
