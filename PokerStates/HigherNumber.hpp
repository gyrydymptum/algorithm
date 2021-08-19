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

// Hard to understand I spent 5 minutes looking, hwat actually hapens and why we asign startPoker here
// Nice solution with state! But this should be initialize in game or sth like this
DicePoker& startPoker = highNumber;
