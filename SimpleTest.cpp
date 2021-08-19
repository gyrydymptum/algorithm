#include "SimpleTest.hpp"

#include "DicePoker.hpp"
#include "PokerStates/PokerStates.hpp"

#include <iostream>
#include <iterator>
#include <random>

namespace {
std::vector<DicesContainer> defaultTestResults = {
    {1, 2, 3, 5, 6},
    {1, 1, 2, 3, 4},
    {1, 1, 2, 2, 3},
    {1, 1, 1, 2, 3},
    {1, 1, 1, 2, 2},
    {1, 1, 1, 1, 2},
    {1, 2, 3, 4, 5},
    {2, 3, 4, 5, 6},
    {1, 1, 1, 1, 1}};

std::vector<DicesContainer> defaultTestResults2 = {
    {1, 2, 3, 5},
    {1, 1},
    {1, 2},
    {1, 2, 1},
    {5, 5, 5},
    {1, 1, 2, 3},
    {1, 1, 2, 2},
    {1, 1, 1, 2},
    {1, 2, 2, 2},
    {1, 1, 1, 1}};
}  // namespace

void SimpleCase() {
    DicePoker* hand;
    for (const auto& dices : defaultTestResults) {
        std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << '\n';
        hand = startPoker.resolve(dices);
        std::cout << hand->getName() << '\n';
        DicePoker::counter = 0;
    }
}

void LessDicesCase() {
    DicePoker* hand;
    for (const auto& dices : defaultTestResults2) {
        std::copy(dices.cbegin(), dices.cend(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << '\n';
        hand = startPoker.resolve(dices);
        std::cout << hand->getName() << '\n';
        DicePoker::counter = 0;
    }
}

void RandomDicesResults() {
    DicePoker* hand;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 6);
    auto rdice = [&distrib, &gen]() { return (int)distrib(gen); };
    do {
        DicesContainer arr = {rdice(), rdice(), rdice(), rdice(), rdice()};
        std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "\n";
        hand = startPoker.resolve(arr);
        std::cout << hand->getName() << '\n';
        DicePoker::counter = 0;
    } while (hand->getName() != "poker");
}
