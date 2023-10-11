#include "WoundTrap.h"
using namespace std;

WoundTrap::WoundTrap()
{
    this->Trt = 'w';
}

int WoundTrap::Wound(int w)
{
    if (this->intruder == true)
    {
        return w -= 500;
    }
}

WoundTrap::~WoundTrap()
{
}

int WoundTrap::ex(int w)
{
    return Wound(w);
}
