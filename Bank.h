#ifndef BANK_H
#define BANK_H
#include "Facility.h"
// #include "Engine.h"
#include <iostream>
#include <string>
using namespace std;

class Engine;

class Bank : public Facility
{
public:
    
    Bank();
    ~Bank();
    int withdraw(int value);
    void deposit(int value);
    void setToEngine();
    void finalize();
    //void setToEngine();
    bool bankRequest(int val);
};

#endif // TASK_2_BANK_H
