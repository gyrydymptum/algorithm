#include "Dice.hpp"

bool operator==(int other, const Dice& dice) {
    return dice.value == other;
}