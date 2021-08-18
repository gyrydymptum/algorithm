#include <string>
#include <iostream>
#include "Counter.hpp"

int main() {
    std::cout << "Romeo and Juliet:\n";
    Counter romeo("../book.txt");
    std::cout << "\nLatin text:\n";
    Counter latin("../Sumfing2.txt");
    return 0;
}