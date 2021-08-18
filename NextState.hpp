#pragma once

#include "Dice.hpp"
#include <list>
#include <functional>

class DicePoker;
using DicesContainer = std::list<Dice>;

#include "Range.hpp"

using ActionFunctor = std::function<bool(const Range&)>;

class NextState {
public:
    NextState(DicePoker& state, const char dicesNumberRequired, ActionFunctor test)
        : state(&state), dicesNumberRequired(dicesNumberRequired), test(test) {}

    bool check(const Range& dices) const {
        return dices.size() >= dicesNumberRequired && test(dices);
    }

    DicePoker* nextState() const {
        return state;
    }

private:
    const ActionFunctor test;
    DicePoker* const state;
    const char dicesNumberRequired;
};
