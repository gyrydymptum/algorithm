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
        std::transform(word.begin(), word.end(), word.begin(), [](auto c) { return std::tolower(c); });
        if (!word.empty()) {
            wordSizeMap_[word.size()].insert(word);
            ++wordCounterMap_[word];
        }
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
    auto it = wordSizeMap_.cbegin();
    if (it->first == 0) {
        ++it;
    }
    std::cout << "Shortest words, (" << it->first << " characters): ";
    std::copy(it->second.cbegin(), it->second.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nLongest words, (" << wordSizeMap_.rbegin()->first << " characters): ";
    std::copy(wordSizeMap_.rbegin()->second.cbegin(),
              wordSizeMap_.rbegin()->second.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    auto minmaxVal = std::minmax_element(wordCounterMap_.cbegin(), wordCounterMap_.cend(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    std::cout << "\nRarest words (occurrences:  " << minmaxVal.first->second << "): ";
    std::for_each(wordCounterMap_.cbegin(), wordCounterMap_.cend(), [&](const auto& pair) {
        if (pair.second == minmaxVal.first->second) {
            std::cout << pair.first << ' ';
        }
    });
    std::cout << "\nMost common words (occurrences:  " << minmaxVal.second->second << "): ";
    std::for_each(wordCounterMap_.cbegin(), wordCounterMap_.cend(), [&](const auto& pair) {
        if (pair.second == minmaxVal.second->second) {
            std::cout << pair.first << ' ';
        }
    });
    std::cout << '\n';
}
