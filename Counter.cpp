#include "Counter.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>

Counter::Counter(const std::string& filePath) {
    std::ifstream inFile{filePath};
    if (!inFile) {
        throw std::invalid_argument("Could not open the file.");
    }
    ss_ << inFile.rdbuf();
    inFile.close();
    fileContent_ = ss_.str();
    calculate();
}

void Counter::calculate() {
    std::string word;
    while (ss_ >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), [](auto c) { return std::ispunct(c); }), word.end());
        wordMap_[word.size()].insert(word);
        ++wordCount_;
    }
    characterCount_ = fileContent_.size();
    lineCount_ = static_cast<size_t>(std::count(fileContent_.cbegin(), fileContent_.cend(), '\n'));
    print();
}

void Counter::print() {
    std::cout << "Characters: " << characterCount_ << '\n';
    std::cout << "Words: " << wordCount_ << '\n';
    std::cout << "Lines: " << lineCount_ << '\n';
    auto it = wordMap_.cbegin();
    if (it->first == 0) {
        ++it;
    }
    std::cout << "Shortest words, " << it->first << " characters: ";
    std::copy(it->second.cbegin(), it->second.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nLongest words, " << wordMap_.rbegin()->first << " characters: ";
    std::copy(wordMap_.rbegin()->second.cbegin(),
              wordMap_.rbegin()->second.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';
}
