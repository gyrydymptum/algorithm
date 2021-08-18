DicePoker onePair(  //2dices or more
    "one pair",
    {
        NextState(
            twoPair, 
            4, 
            [](auto dices) {  //
                auto it = std::adjacent_find(
                    dices.cbegin(),
                    dices.cend());
                auto it2 = std::adjacent_find(
                    dices.crbegin(),
                    dices.crend());
                return *it != *it2;
            }),
        NextState(
            triplet, 
            3, 
            [](auto dices) {
                auto it = dices.cbegin();
                std::advance(it, 2);
                it = std::search_n(dices.cbegin(), dices.cend(), 3, *it);
                return it != dices.cend();
            })
    }
);