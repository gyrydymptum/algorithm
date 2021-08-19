#include "NextState.hpp"

NextState::NextState(DicePoker& state, unsigned char dicesNumberRequired, ActionFunctor test)
    : state(&state), dicesNumberRequired(dicesNumberRequired), test(test) {}

bool NextState::check(const DicesContainer& dices) const {
    return dices.size() >= dicesNumberRequired && test(dices);
}

DicePoker* NextState::nextState() const {
    return state;
}