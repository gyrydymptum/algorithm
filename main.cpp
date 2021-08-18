// Zadanie2: Napisz program, który będzie sprawdzał wynik w kościanego pokera.
//   Opis:
//     - Dostępne są następujące wyniki (nie jest to zgodne z Wikipedią), w nawiasach podano przykładowy rzut spełniający wymogi:
// 	HigherNumber, (1, 2, 3, 5, 6)
// 	OnePair, (1, 1, 2, 3, 4)
// 	TwoPair, (1, 1, 2, 2, 3)
// 	Triplet, (1, 1, 1, 2, 3)
// 	Full, (1, 1, 1, 2, 2)
// 	Quadruplets, (1, 1, 1, 1, 2)
// 	SmallStrit, (1, 2, 3, 4, 5)
// 	BigStrit, (2, 3, 4, 5, 6)
// 	Poker (1, 1, 1, 1, 1)
//   Zasady:
// 	- Wykorzystajcie programowanie obiektowe.
// 	- Koda ma być prosty bez zawiłej ifologi i skomplikowanego łączenia wielu predykatów.
// 	- Maksymalna ilość dopuszczalnych 'if' to 10 (da się o zrobić za pomocą 9 lub pewnie nawet mniej).
// 	- Każdy 'if' więcej to -2 eurogąbki (nie można zejść poniżej 0 za to zadanie, więc spokojnie).
// 	- 'else' i 'else if' to też if.
// 	- :? to także `if - else` więc również jest zaliczany jako `if`.
// 	- Rozrysuj sobie na kartce, jakie są możliwości i zastanów sie, jaka jest korelacja między wynikami.
// 	- Za poprawne rozwiązanie zadania 15 eurogąbek
// 	- Za dodanie testów 5 (GTEST/ CATCH) eurogąbek
// 	- Finalna liczba punktów: ZDOBYTE_PUNKTY - (ILOŚĆ_IF_POWYŻEJ_10 * 2)
// 	- Jeżeli wyjdzie Ci nawet 15 ifów to i tak dalej możesz zdobyć 10 punktów! (20 - (5 * 2)) = 10!

// 9 przejść == 9 ifów
//            HigherNumber
//            /    \    \
//           /      \     \
//          /        \      \
//         /          \       \
//      OnePair    BigStrit    SmallStrit
//     /       \
// TwoPair   Triplet
//    |       / |
//    |     /   |
//    |   /     |
//    | /       |
// Full      Quadruplets
//              |
//            Poker

//Pytanie czy testujemy pełne 5 rzutów czy co rzut by ocenić swoje szanse?

#include "DicePoker.hpp"
#include "PokerStates.hpp"
#include <memory>
#include <numeric>

void Game() {
    DicePoker* hand;

    hand = highNumber.addDice({1, 2, 3, 5, 6});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 1, 2, 3, 4});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 1, 2, 2, 3});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 1, 1, 2, 3});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 1, 1, 2, 2});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 1, 1, 1, 2});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 2, 3, 4, 5});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({2, 3, 4, 5, 6});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;

    hand = highNumber.addDice({1, 1, 1, 1, 1});
    std::cout << hand->name << '\n';
    DicePoker::counter = 0;
}

int main() {
    Game();
    return 0;
}