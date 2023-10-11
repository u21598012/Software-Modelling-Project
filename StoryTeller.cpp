#include "StoryTeller.h"
#include <string>
#include <vector>
using namespace std;

StoryTeller::StoryTeller()
{}

StoryTeller::~StoryTeller()
{}

Hero* StoryTeller::spawn(char type)
{
    if(type == 'r')
    {
        return new ReverseHero();
    }
    else
    {
        if(type = 'h')
        {
            return new HorizontalHero();
        }
    }
}