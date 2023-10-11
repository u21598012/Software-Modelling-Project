#ifndef STORY_TELLER_H
#define STORY_TELLER_H
#include <string>
#include "Hero.h"
#include "ReverseHero.h"
#include "HorizontalHero.h"
using namespace std;

class StoryTeller
{
private:
public:
    // variables:
    // functions:
    StoryTeller();
    ~StoryTeller();
    Hero *spawn(char type);
};

#endif // STORYTELLER_H