#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#include <random>

std::vector<int> v{1, 2, 3,};
std::vector<std::string> vs{"1","2","3"};

void print_sample() {
    std::sample(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "),
                v.size(), std::mt19937{std::random_device{}()});
}

void print_copy() {
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
}

void print_copy_n() {
    std::copy_n(begin(v), v.size(), std::ostream_iterator<int>(std::cout, " "));
}

void print_copy_if() {
    std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "),
                 [](const auto& value) {
                     return value < std::numeric_limits<int>::max();
                 });
}

void print_for_each() {
    std::for_each(begin(v), end(v), [](const auto& el) {
        std::cout << el << " ";
    });
}

void print_for_each_n() {
    std::for_each_n(begin(v), v.size(), [](const auto& el) {
        std::cout << el << " ";
    });
}

void print_transform() {
    std::transform(begin(v),
                   end(v),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](const auto& el) { return el; });
}

void print_move() {
    std::move(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
}

void print_reverse_copy() {
    std::reverse_copy(std::rbegin(v), std::rend(v), std::ostream_iterator<int>(std::cout, " "));
}

void print_rotate_copy() {
    std::rotate_copy(begin(v), end(v), end(v),
                     std::ostream_iterator<int>(std::cout, " "));
}

void print_reduce() {
    std::cout << std::reduce(begin(vs), end(vs), std::string{},
                             [](auto result, auto value) {
                                 return result + value + " ";
                             });
}

void print_accumulate() {
    std::cout << std::accumulate(begin(vs), end(vs), std::string{});
}

int main() {
    std::cout << "\nprint_sample\n";
    print_sample();
    std::cout << "\nprint_copy\n";
    print_copy();
    std::cout << "\nprint_copy_n\n";
    print_copy_n();
    std::cout << "\nprint_copy_if\n";
    print_copy_if();
    std::cout << "\nprint_for_each\n";
    print_for_each();
    std::cout << "\nprint_for_each_n\n";
    print_for_each_n();
    std::cout << "\nprint_transform\n";
    print_transform();
    std::cout << "\nprint_move\n";
    print_move();
    std::cout << "\nprint_reverse_copy\n";
    print_reverse_copy();
    std::cout << "\nprint_rotate_copy\n";
    print_rotate_copy();
    std::cout << "\nprint_reduce\n";
    print_reduce();
    std::cout << "\nprint_accumulate\n";
    print_accumulate();
    std::cout << '\n';
    return 0;
}
