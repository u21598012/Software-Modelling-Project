#include "Hero.h"
#include <string>
#include <vector>
using namespace std;

Hero::Hero()
{
    this->balance = 0;
    this->health = 1000;
}

Hero::~Hero() {}

void Hero::Search(Lair *l, int index) {}

int Hero::React(tile *t)
{
    t->hasHero = true;
    if (t->trap != NULL)
    {
        if (t->trap->Trt == 'r')
        {
            return t->trap->ex(this->balance);
        }
        else
        {
            if (t->trap->Trt == 'w')
            {
                return t->trap->ex(this->health);
            }
        }
    }

    // t->hero = this;
}
