#include "ResearchLab.h"
using namespace std;

ResearchLab::ResearchLab() {}

Trap *ResearchLab::produceTrap(char type)
{
    Trap *trap = nullptr;

    if (type == 'R')
    {
        trap = new ReclaimTrap();
    }
    else if (type == 'W')
    {
        trap = new WoundTrap();
    }

    if (trap != nullptr)
    {
        // Add the trap to the production queue
        lock_guard<std::mutex> lock(queueMutex);
        productionQueue.push(trap);
        this->e->start();
        // Return immediately after adding to the queue
        return trap;
    }

    return nullptr;
}

void ResearchLab::finalize()
{
    Trap *trap = nullptr;
    if (!productionQueue.empty())
    {
        trap = productionQueue.front();
        productionQueue.pop();
    }

    if (trap != nullptr)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        auto currentTime = startTime;
        const std::chrono::seconds duration(10);

        while (currentTime - startTime < duration)
        {
            currentTime = std::chrono::high_resolution_clock::now();
        }
        RFU.push(trap);
    }
}

bool ResearchLab::bankRequest(int val)
{
    this->e->processRequest(val);
}

void ResearchLab::setToEngine()
{
    this->e->rl = this;
}

int ResearchLab::withdraw(int value)
{
}

void ResearchLab::deposit(int value)
{
}

void ResearchLab::trigger()
{
    this->e->start();
}
