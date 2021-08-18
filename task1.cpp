#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> v{1, 2, 3};

void print1() {
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
}
void print2() {
    std::for_each(v.begin(), v.end(), [](const auto& el) {
        std::cout << el << " ";
    });
}
void print3() {
    std::transform(begin(v),
                   end(v),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](const auto& el) { return el; });
}
void print4() {
    std::reverse_copy(std::rbegin(v), std::rend(v), std::ostream_iterator<int>(std::cout, " "));
}
void print5() {
}
void print6() {
}
void print7() {
}
void print8() {
}
void print9() {
}
void print10() {
}

std::vector<void (*)()> printFuncs = {
    print1,
    print2,
    print3,
    print4,
    print5,
    print6,
    print7,
    print8,
    print9,
    print10,
};

int main() {
    for (const auto& func : printFuncs) {
        func();
        std::cout << '\n';
    }

    return 0;
}
