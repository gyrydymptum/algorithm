#pragma once

#include "NextState.hpp"
#include <vector>
#include <iostream>

using StateContainer = std::vector<NextState>;

class DicePoker{
public:
    DicePoker(std::string name, StateContainer options)
        : name(name), options(options) {}
    ~DicePoker() = default;

    static int counter;

    [[nodiscard]] DicePoker * addDice(Range& diceRange) {
        for (const auto &option : options){
            if (option.check(diceRange)){
                auto state = option.nextState();
                //std::cout << "state changed to: " << state->name << '\n';
                return state;
            }
            ++counter;
        }
        return this;
    }

    [[nodiscard]] DicePoker * addDice(DicesContainer newdices){
        newdices.sort();
        size_t dicesNum = 2;
        
        auto hand = this;
        auto newhand = this;
        Range range(newdices, 5);
        do {
            hand = newhand;
            newhand = hand->addDice(range);
            ++dicesNum;
        } while (hand != newhand);
        std::cout << "counter of ifs reach: " << counter <<'\n';
        return hand;
    }
    std::string name = "default";

private:
    StateContainer options;
};

int DicePoker::counter = 0;
