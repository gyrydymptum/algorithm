#include <string>
#include <iostream>
#include "Counter.hpp"

int main() {
    std::cout << "Romeo and Juliet:\n";
    Counter("../book.txt");
    std::cout << "\nLatin text:\n";
    Counter("../Sumfing2.txt");
    return 0;
}