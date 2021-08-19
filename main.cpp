#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

void print(std::string str) {
    std::copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout));
    std::cout << '\n';
}

std::string readTextFromFile(std::string filetxt) {
    using istream_it = std::istream_iterator<char>;
    std::ifstream file(filetxt);
    std::string file_contents;
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open the file.");
    }
    file >> std::noskipws;
    std::copy(istream_it(file), istream_it(), std::back_inserter(file_contents));
    file.close();
    return file_contents;
}

void convertText(std::string filetxt) {
    std::string file_contents = readTextFromFile(filetxt);
    std::cout << "ORIGINAL TEXT:\n";
    print(file_contents);
    file_contents.erase(std::unique(file_contents.begin(), file_contents.end(), [](auto& lhs, auto& rhs) {
                            return lhs == rhs && std::isspace(lhs);
                        }),
                        file_contents.end());
    std::cout << "CONVERTED TEXT:\n";
    print(file_contents);
}

int main() {
    convertText("../Sumfing.txt");

    return 0;
}