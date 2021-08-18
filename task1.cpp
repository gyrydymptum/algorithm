#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> v{1, 2, 3};

void print1() {
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
void print2() {
    std::for_each(begin(v), end(v), [](const auto& el) {
        std::cout << el << " ";
    });
    std::cout << '\n';
}
void print3() {
    std::transform(begin(v),
                   end(v),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](const auto& el) { return el; });
    std::cout << '\n';
}
void print4() {
    std::move(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
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
    }

    return 0;
}
