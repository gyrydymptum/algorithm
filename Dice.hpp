#pragma once
#include <algorithm>

class Dice {
public:
    constexpr Dice(int value)
        : value(value) 
    {
        value = std::clamp(1, value, 6);
    }

    operator int() const {
        return value;
    }

    template <typename T>
    bool operator==(const T other) {
        return value == other;
    }

    friend bool operator==(int other, const Dice& dice);

private:
    int value;
};
