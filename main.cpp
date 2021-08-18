#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

void print(std::string str) {
    std::copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout));
}

void convertedText(std::string filetxt) {
    std::ifstream file(filetxt);
    std::string str;
    std::string file_contents;
    if (file.is_open()) {
        while (std::getline(file, str)) {
            file_contents += str;
            file_contents.push_back('\n');
        }
        file.close();
    }
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
    convertedText("Sumfing.txt");

    return 0;
}
