#include "DicePoker.hpp"
#include <iostream>

int DicePoker::counter = 0;

DicePoker::DicePoker(std::string name, StateContainer options)
    : name(name), options(options) {}

DicePoker* DicePoker::resolve(DicesContainer newdices) {
    newdices.sort();
    auto hand = this;
    auto newhand = this;
    do {
        hand = newhand;
        newhand = hand->checkRange(newdices);
    } while (hand != newhand);
    std::cout << "counter of ifs reach: " << counter << '\n';
    return hand;
}

std::string DicePoker::getName() const {
    return name;
}

DicePoker* DicePoker::checkRange(DicesContainer& diceRange) {
    for (const auto& option : options) {
        ++counter;
        if (option.check(diceRange)) {
            auto state = option.nextState();
            //std::cout << "state changed to: " << state->name << '\n';
            return state;
        }
    }
    return this;
}