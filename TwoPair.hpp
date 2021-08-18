DicePoker twoPair(  //4dices or more
    "two pairs",
    {NextState(full, 5, [](auto dices) {
        auto it = std::search_n(
            dices.cbegin(),
            dices.cend(),
            3,
            *dices.cbegin());
        auto it2 = std::search_n(
            dices.crbegin(),
            dices.crend(),
            3,
            *dices.crbegin());
        return it != dices.cend() || it2 != dices.crend();
    })});