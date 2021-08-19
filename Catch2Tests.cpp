#include <array>
#include "Catch_amalgamated.hpp"
#include "DicePoker.hpp"
#include "PokerStates/PokerStates.hpp"

std::array names = {
    "high number",  //
    "big strit",    //
    "small strit",  //
    "one pair",     //
    "two pairs",    //
    "triplet",      //
    "full",         //
    "quadruplets",  //
    "poker",        //
};

#include <iostream>

TEST_CASE("Test legal dices") {
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    Dice dice{x};
    REQUIRE(dice == x);
}

TEST_CASE("Test ilegal dices") {
    auto x = GENERATE(-5, -1, 0, 7, 8, std::numeric_limits<int>::min(), std::numeric_limits<int>::min() / 2, std::numeric_limits<int>::max(), std::numeric_limits<int>::max() / 2);
    Dice dice{x};
    REQUIRE(dice < 7);
    REQUIRE(dice > 0);
}

TEST_CASE("Test high number") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    auto y = GENERATE(1, 2);
    dices.push_back(x);
    y = x + y;
    dices.push_back(y <= 6 ? y : y - 6);
    dices.push_back(++y <= 6 ? y : y - 6);
    dices.push_back(++y <= 6 ? y : y - 6);
    dices.push_back(++y <= 6 ? y : y - 6);

    if (std::is_permutation(begin(dices), end(dices), DicesContainer{1, 2, 3, 4, 5}.begin())) {
        return;
    }
    if (std::is_permutation(begin(dices), end(dices), DicesContainer{2, 3, 4, 5, 6}.begin())) {
        return;
    }

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "high number");
}

TEST_CASE("Test big strit") {
    DicesContainer dices{2, 3, 4, 5, 6};

    auto x = GENERATE(1, 2, 3, 4, 5);
    auto it = begin(dices);
    std::advance(it, x);
    std::rotate(begin(dices), it, end(dices));

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "big strit");
}

TEST_CASE("Test small strit") {
    DicesContainer dices{1, 2, 3, 4, 5};

    auto x = GENERATE(1, 2, 3, 4, 5);
    auto it = begin(dices);
    std::advance(it, x);
    std::rotate(begin(dices), it, end(dices));

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "small strit");
}

TEST_CASE("Test one pair") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    auto y = GENERATE(1, 2, 3);
    dices.push_back(x);
    dices.push_back(x);
    y = x + y;
    dices.push_back(y <= 6 ? y : y - 6);
    dices.push_back(++y <= 6 ? y : y - 6);
    dices.push_back(++y <= 6 ? y : y - 6);

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "one pair");
}

TEST_CASE("Test two pairs") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    auto y = GENERATE(1, 2, 3, 4);
    dices.push_back(x);
    dices.push_back(x);
    y = x + y;
    y = (y <= 6) ? y : y - 6;
    dices.push_back(y);
    dices.push_back(y);
    dices.push_back(++y <= 6 ? y : y - 6);

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "two pairs");
}

TEST_CASE("Test full") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    auto y = GENERATE(1, 2, 3, 4, 5);
    auto rot = GENERATE(1, 2, 3, 4, 5);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);
    y = x + y;
    y = (y <= 6) ? y : y - 6;
    dices.push_back(y);
    dices.push_back(y);
    auto it = dices.begin();
    std::advance(it, rot);
    std::rotate(dices.begin(), it, dices.end());

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "full");
}

TEST_CASE("Test triple") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    auto y = GENERATE(1, 2, 3, 4);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);
    y = x + y;
    dices.push_back(y <= 6 ? y : y - 6);
    dices.push_back(++y <= 6 ? y : y - 6);

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "triplet");
}

TEST_CASE("Test quadruplets") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    auto y = GENERATE(1, 2, 3, 4, 5);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);
    y = x + y;
    dices.push_back(y <= 6 ? y : y - 6);

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "quadruplets");
}

TEST_CASE("Test poker") {
    DicesContainer dices;
    auto x = GENERATE(1, 2, 3, 4, 5, 6);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);
    dices.push_back(x);

    std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    DicePoker* hand = startPoker.resolve(dices);
    std::cout << hand->getName() << '\n';

    REQUIRE(hand->getName() == "poker");
}