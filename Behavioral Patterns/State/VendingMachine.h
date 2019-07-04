#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include "IState.h"

class VendingMachine
{
private:
    IState * mIdleState;
    IState * mHasCashState;
    IState * mCurrentState;
    int mCashValue = 0;
public:
    VendingMachine();
    void setState(IState * state) {
        mCurrentState = state;
    }
    IState * getIdleState() const { return mIdleState; }
    IState * getHasCashState() const { return mHasCashState; }
    void setCashValue(int cash) { mCashValue += cash; }
    int getCashValue() const { return mCashValue; }
    void insertCash(int cash) { mCurrentState->insertCash(cash); }
    void dispense() { mCurrentState->dispense(); }
    void ejectCash() { mCurrentState->ejectCash(); }
    ~VendingMachine();
};
#endif //VENDINGMACHINE_H