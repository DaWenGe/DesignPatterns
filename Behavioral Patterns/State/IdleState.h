#ifndef IDLESTATE_H
#define IDLESTATE_H
#include "IState.h"
#include <iostream>
#include "VendingMachine.h"

using namespace std;
class IdleState : public IState {
private:
    VendingMachine * mVendingMachine;
public:
    IdleState(VendingMachine * machine) : mVendingMachine(machine) {
        std::cout << "IdleState constructed! " << std::endl;
    }

    void insertCash(int money) override {
        mVendingMachine->setCashValue(money);
        std::cout << "IdleState::Got some money: " << money << std::endl;
        std::cout << "IdleState::Change to 'hasCashState' " << std::endl;
        mVendingMachine->setState(mVendingMachine->getHasCashState());
    }

    void ejectCash() override {
        std::cout << "IdleState::No cash inserted! Please insert cash first!" << endl;
    }

    void dispense() override {
        std::cout << "IdleState::Cannot dispense, no cash found!" << endl;
    }

    ~IdleState() {
        std::cout << "IdleState::IdleState desctructed! " << std::endl;
    };
};
#endif // IDLESTATE_H