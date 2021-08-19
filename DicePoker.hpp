#pragma once
#include <vector>
#include "NextState.hpp"

using StateContainer = std::vector<NextState>;

class DicePoker {
public:
    static int counter;

    DicePoker(std::string name, StateContainer options);
    ~DicePoker() = default;

    [[nodiscard]] DicePoker* resolve(DicesContainer newdices);

    std::string getName() const;

private:
    [[nodiscard]] DicePoker* checkRange(DicesContainer& diceRange);

    std::string name;
    StateContainer options;
};
