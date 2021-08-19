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

    // use "sth_" -> it will be easier to know which variable is member
    std::string name;
    StateContainer options;
};
