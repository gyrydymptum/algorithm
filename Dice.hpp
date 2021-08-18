#pragma once

#include <algorithm>

class Dice {
public:
    Dice() = default;
    constexpr Dice(int value)
        : value(value) {
        value = std::clamp(1, value, 6);
    }

    operator int() const {
        return value;
    }

    template <typename T>
    bool operator==(const T other) {
        return value == other;
    }

    friend bool operator==(int other, const Dice& dice) {
        return dice.value == other;
    }

    void print() const;
    int getValue() const;

private:
    int value = 0;
};
