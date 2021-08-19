#pragma once
DicePoker highNumber(
    "high number",
    {
        NextState(
            onePair, 
            2, 
            [](const auto& dices) {
                auto it = std::adjacent_find(dices.cbegin(), dices.cend());
                return it != dices.cend();
            }
        ),
        NextState(
            bigStrit, 
            5, 
            [](const auto& dices) {
                return std::equal(dices.cbegin(), dices.cend(), DicesContainer{2, 3, 4, 5, 6}.begin());
            }
        ),
        NextState(
            smallStrit, 
            5, 
            [](const auto& dices) {
                return std::equal(dices.cbegin(), dices.cend(), DicesContainer{1, 2, 3, 4, 5}.begin());
            }
        )
    }
);

DicePoker& startPoker = highNumber;
