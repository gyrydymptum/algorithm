#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

void print(std::string str) {
    std::copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout));
    std::cout << '\n';
}

// std::string readTextFromFile(std::string filetxt) {
//     std::ifstream file(filetxt);
//     std::string str;
//     std::string file_contents;
//     if (file.is_open()) {
//         while (std::getline(file, str)) {
//             file_contents += str;
//             file_contents.push_back('\n');
//         }
//         file.close();
//     }
//     return file_contents;
// }
std::string readTextFromFile(const std::string& filetxt) {
    std::ifstream inFile{filetxt};
    std::stringstream str;
    std::string file_contents;
    if (!inFile) {
        throw std::invalid_argument("Could not open the file.");
    }
    str << inFile.rdbuf();
    inFile.close();
    file_contents = str.str();
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
    convertText("Sumfing.txt");

    return 0;
}

