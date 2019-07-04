#include <iostream>
#include "VendingMachine.h"
#include "IdleState.h"
#include "HasCashState.h"

using namespace std;
VendingMachine::VendingMachine() {
    mIdleState = new IdleState(this);
    mHasCashState = new HasCashState(this);
    mCurrentState = mIdleState;
    std::cout << "VendingMachine constructed!" << std::endl;
}

VendingMachine::~VendingMachine() {
    delete mIdleState;
    delete mHasCashState;
    mIdleState = nullptr;
    mHasCashState = nullptr;
    mCurrentState = nullptr;
    std::cout << "VendingMachine destructed!" << std::endl;
}