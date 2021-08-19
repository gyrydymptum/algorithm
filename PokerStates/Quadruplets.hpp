#pragma once
#include <numeric>
DicePoker quadruplets(  //4dices or more
    "quadruplets",
    {
        NextState(
            poker, 
            5, 
            [](const auto& dices) {
                return *dices.cbegin() == *dices.crbegin();
            }
        )
    }
);
