#include "Counter.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

Counter::Counter(const std::string& filePath) {
    std::ifstream inFile{filePath};
    if (!inFile) {
        throw std::invalid_argument("Could not open the file.");
    }
    readFromFile(inFile);
    inFile.close();
    print();
}

void Counter::readFromFile(const std::ifstream& inFile) {
    std::stringstream ss;
    ss << inFile.rdbuf();
    WordCounterMapType wordCounterMap;
    std::string word;
    while (ss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), [](auto c) { return std::ispunct(c); }), word.end());
        std::transform(word.begin(), word.end(), word.begin(), [](auto c) { return std::tolower(c); });
        if (!word.empty()) {
            wordSizeMap_[word.size()].insert(word);
            ++wordCounterMap[word];
        }
        ++wordCount_;
    }
    std::string fileContent{ss.str()};
    characterCount_ = fileContent.size();
    lineCount_ = static_cast<size_t>(std::count(fileContent.cbegin(), fileContent.cend(), '\n'));
    rareCommonWordsFill(wordCounterMap);
}

void Counter::rareCommonWordsFill(const WordCounterMapType& map) {
    auto minmaxVal = std::minmax_element(map.cbegin(), map.cend(),
                                         [](const auto& a, const auto& b) {
                                             return a.second < b.second;
                                         });
    std::vector<std::pair<std::string, size_t>> rareWordsPair;
    std::copy_if(map.cbegin(), map.cend(), std::back_inserter(rareWordsPair), [&](const auto& pair) {
        return pair.second == minmaxVal.first->second;
    });
    rareWords_.reserve(rareWordsPair.size());
    std::transform(rareWordsPair.cbegin(), rareWordsPair.cend(), std::back_inserter(rareWords_), [](const auto& word) {
        return word.first;
    });

    std::vector<std::pair<std::string, size_t>> commonWordsPair;
    std::copy_if(map.cbegin(), map.cend(), std::back_inserter(commonWordsPair), [&](const auto& pair) {
        return pair.second == minmaxVal.second->second;
    });
    commonWords_.reserve(commonWordsPair.size());
    std::transform(commonWordsPair.cbegin(), commonWordsPair.cend(), std::back_inserter(commonWords_), [](const auto& word) {
        return word.first;
    });
    minMaxCounts_ = std::make_pair(minmaxVal.first->second, minmaxVal.second->second);
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
    std::cout << "\nRarest words (occurrences:  " << minMaxCounts_.first << "): ";
    std::copy(rareWords_.cbegin(), rareWords_.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nMost common words (occurrences:  " << minMaxCounts_.second << "): ";
    std::copy(commonWords_.cbegin(), commonWords_.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';
}
