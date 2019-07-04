#include "VendingMachine.h"

int main() {
    VendingMachine * machine = new VendingMachine();
    machine->insertCash(100);
    machine->dispense();
    machine->insertCash(20);
    machine->ejectCash();
    delete machine;
}