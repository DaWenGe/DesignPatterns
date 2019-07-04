#ifndef HASCASHSTATE_H
#define HASCASHSTATE_H
#include <iostream>
#include "IState.h"
#include "VendingMachine.h"

using namespace std;
class HasCashState : public IState
{
private:
    VendingMachine * mVendingMachine;
public:
    HasCashState(VendingMachine * machine);

    void insertCash(int money) override {
        std::cout << "HasCashState::Adding some money: " << money << std::endl;
    }

    void ejectCash() override {
        std::cout << "HasCashState::Ejecting all the cash!" << std::endl;
        mVendingMachine->setCashValue(0);
        mVendingMachine->setState(mVendingMachine->getIdleState());
    }

    void dispense() override {
        std::cout << "HasCashState::Dispense product!" << std::endl;
        mVendingMachine->setCashValue(0);
        std::cout << "HasCashState::1" << std::endl;
        mVendingMachine->setState(mVendingMachine->getIdleState());
        std::cout << "HasCashState::2" << std::endl;
    }
    
    ~HasCashState();
};

HasCashState::HasCashState(VendingMachine * machine)
{
    std::cout << "HasCashState constructed!" << std::endl;
}

HasCashState::~HasCashState()
{
    std::cout << "HasCashState destructed!" << std::endl;
}

#endif // HASCASHSTATE_H