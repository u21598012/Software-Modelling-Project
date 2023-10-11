#include "Facility.h"

Facility::Facility() {}

Facility::~Facility()
{
    while (!RFU.empty())
    {
        delete RFU.front(); // Delete the object pointed to by the front of the queue
        RFU.pop();          // Remove the pointer from the queue
    }
}

Trap *Facility::produceTrap(char type)
{
    return NULL;
}

// void Facility::attach()
// {
//     this->e->.push(this);
// }
