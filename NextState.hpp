#pragma once
#include <functional>
#include <list>
#include "Dice.hpp"

class DicePoker;
using DicesContainer = std::list<Dice>;
using ActionFunctor = std::function<bool(const DicesContainer&)>;

class NextState {
public:
    NextState(DicePoker& state, unsigned char dicesNumberRequired, ActionFunctor test);
    bool check(const DicesContainer& dices) const;
    DicePoker* nextState() const;

private:
    const ActionFunctor test;
    DicePoker* const state;
    const unsigned char dicesNumberRequired;
};
