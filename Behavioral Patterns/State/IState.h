#ifndef ISTATE_H
#define ISTATE_H

class IState
{
public:
    IState() = default;
    virtual void insertCash(int money) = 0;
    virtual void ejectCash() = 0;
    virtual void dispense() = 0;

    virtual ~IState() = default;
};
#endif // ISTATE_H