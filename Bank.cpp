#include "Bank.h"
using namespace std;

Bank::Bank()
{
    this->balance = 1000;
}

Bank::~Bank() {}

void Bank::deposit(int value)
{
    this->balance += value;
}

int Bank::withdraw(int value)
{
    if (value <= balance)
    {
        this->balance -= value;
        return value;
    }
    else
    {
        cout << "Insuffucient Funds" << endl;
        return 0;
    }
}

void Bank::setToEngine()
{
    this->e->b = this;
}

void Bank::finalize()
{
}

bool Bank::bankRequest(int val)
{
}