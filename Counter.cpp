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
    calculate(inFile);
    inFile.close();
    print();
}

void Counter::calculate(const std::ifstream& inFile) {
    std::stringstream ss;
    ss << inFile.rdbuf();
    std::string word;
    while (ss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), [](auto c) { return std::ispunct(c); }), word.end());
        std::transform(word.begin(), word.end(), word.begin(), [](auto c) { return std::tolower(c); });
        if (!word.empty()) {
            wordSizeMap_[word.size()].insert(word);
            ++wordCounterMap_[word];
        }
        ++wordCount_;
    }
    std::string fileContent {ss.str()};
    characterCount_ = fileContent.size();
    lineCount_ = static_cast<size_t>(std::count(fileContent.cbegin(), fileContent.cend(), '\n'));
}

void Counter::print() {
    std::cout << "Characters: " << characterCount_ << '\n';
    std::cout << "Words: " << wordCount_ << '\n';
    std::cout << "Lines: " << lineCount_ << '\n';
    std::cout << "Shortest words, (" << wordSizeMap_.cbegin()->first << " characters): ";
    std::copy(wordSizeMap_.cbegin()->second.cbegin(),
              wordSizeMap_.cbegin()->second.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nLongest words, (" << wordSizeMap_.rbegin()->first << " characters): ";
    std::copy(wordSizeMap_.rbegin()->second.cbegin(),
              wordSizeMap_.rbegin()->second.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    auto minmaxVal = std::minmax_element(wordCounterMap_.cbegin(), wordCounterMap_.cend(),
                                         [](const auto& a, const auto& b) {
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
