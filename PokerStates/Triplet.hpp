#pragma once
DicePoker triplet(  //3dices or more
    "triplet",
    {
        NextState(
            quadruplets, 
            4, 
            [](const auto& dices) {
                auto it = std::search_n( dices.cbegin(), dices.cend(), 4, *dices.cbegin());
                auto it2 = std::search_n(dices.crbegin(), dices.crend(), 4, *dices.crbegin());
                return it != dices.cend() || it2 != dices.crend();
            }
        ),
        NextState(
            full, 
            5, 
            [](const auto& dices) {
                auto it = std::adjacent_find(dices.cbegin(), dices.cend());
                auto it2 = std::adjacent_find(dices.crbegin(), dices.crend());
                return *it != *it2;
            }
        )
    }
);
