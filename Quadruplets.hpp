#pragma once

#include <numeric>

DicePoker quadruplets(  //4dices or more
    "quadruplets",
    {NextState(poker, 5, [](auto dices) {
        return *dices.cbegin() == *dices.crbegin();
		//return std::accumulate(dices.cbegin(), dices.cend(), 0) % 5 == 0;
    })});