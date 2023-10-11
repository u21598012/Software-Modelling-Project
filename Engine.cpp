#include "Engine.h"
#include <string>
#include <vector>
using namespace std;

Engine::Engine() {}

Engine::Engine(Facility *lab, Facility *bank)
{
    this->rl = lab;
    this->b = bank;
}

Engine::~Engine()
{
    delete this->b;
    delete this->rl;
}

bool Engine::processRequest(int val)
{
    this->b->withdraw(val);
}

void Engine::start()
{
    cout << endl;
    cout << "Bank balance: " << this->b->balance << endl;
    cout << "Production Queue: ";

    queue<Trap *> tempQueue = this->rl->productionQueue;
    while (!tempQueue.empty())
    {
        Trap *trap = tempQueue.front();
        cout << "<<Trap Type: " << trap->Trt << ">>";
        tempQueue.pop();
    }
    cout << endl;
    cout << "Ready for use: ";
    queue<Trap *> tempQueue1 = this->rl->RFU;
    while (!tempQueue1.empty())
    {
        Trap *trap1 = tempQueue1.front();
        cout << "<<Trap Type: " << trap1->Trt << ">>";
        tempQueue1.pop();
    }
    cout << endl;
}
