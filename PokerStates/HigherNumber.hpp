#pragma once
DicePoker highNumber(
    "high number",
    {
        NextState(
            onePair, 
            2, 
            [](auto dices) {
                auto it = std::adjacent_find(dices.cbegin(), dices.cend());
                return it != dices.cend();
            }
        ),
        NextState(
            bigStrit, 
            5, 
            [](auto dices) {
                return std::is_permutation(dices.cbegin(), dices.cend(), std::begin({2, 3, 4, 5, 6}));
            }
        ),
        NextState(
            smallStrit, 
            5, 
            [](auto dices) {
                return std::is_permutation(dices.cbegin(), dices.cend(), std::begin({1, 2, 3, 4, 5}));
            }
        )
    }
);
