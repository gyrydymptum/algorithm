#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <string>

std::vector<int> v{1, 2, 3, 0, 0, 4, 5, 6};
std::vector<std::string> vs{"4", "5", "6"};

void print_copy() {
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
}

void print_copy_if() {
    std::copy_if(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "),
    [](const auto& value){
        return value >0;
    });
}

void print_for_each() {
    std::for_each(begin(v), end(v), [](const auto& el) {
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

void print6() {
}

void print7() {
}

void print8() {
}

void print9() {
}

void print_reduce() {
    std::cout << std::reduce(begin(vs), end(vs), std::string{},
    [](auto result, auto value){
        return result + value + " ";
    });
}

void print_accumulate() {
    std::cout << std::accumulate(begin(vs), end(vs), std::string{});
}

int main() {
    print_copy();
    std::cout<<'\n';
    print_copy_if();
    std::cout<<'\n';
    print_for_each();
    std::cout<<'\n';
    print_transform();
    std::cout<<'\n';
    print_move();
    std::cout<<'\n';
    print_reverse_copy();
    std::cout<<'\n';
    print7();
    std::cout<<'\n';
    print8();
    std::cout<<'\n';
    print9();
    std::cout<<'\n';
    print_reduce();
    std::cout<<'\n';
    print_accumulate();
    std::cout<<'\n';
    return 0;
}
