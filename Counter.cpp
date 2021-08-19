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
    // You cna achieve it using STL so I will grant you 1 points
    std::stringstream ss;
    ss << inFile.rdbuf();
    WordSizeMapType wordSizeMap;
    WordCounterMapType wordCounterMap;
    std::string word;
    while (ss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), [](auto c) { return std::ispunct(c); }), word.end());
        std::transform(word.begin(), word.end(), word.begin(), [](auto c) { return std::tolower(c); });
        if (!word.empty()) {
            wordSizeMap[word.size()].insert(word);
            ++wordCounterMap[word];
        }
        ++wordCount_;
    }
    std::string fileContent{ss.str()};
    characterCount_ = fileContent.size();
    lineCount_ = static_cast<size_t>(std::count(fileContent.cbegin(), fileContent.cend(), '\n'));
    rareCommonWordsFill(wordCounterMap);
    shortLongWordsFill(wordSizeMap);
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
    std::transform(rareWordsPair.cbegin(), rareWordsPair.cend(), std::back_inserter(rareWords_),
                   [](const auto& word) {
                       return word.first;
                   });
    std::vector<std::pair<std::string, size_t>> commonWordsPair;
    std::copy_if(map.cbegin(), map.cend(), std::back_inserter(commonWordsPair), [&](const auto& pair) {
        return pair.second == minmaxVal.second->second;
    });
    commonWords_.reserve(commonWordsPair.size());
    std::transform(commonWordsPair.cbegin(), commonWordsPair.cend(), std::back_inserter(commonWords_),
                   [](const auto& word) {
                       return word.first;
                   });
    minMaxCounts_ = std::make_pair(minmaxVal.first->second, minmaxVal.second->second);
}

void Counter::shortLongWordsFill(const WordSizeMapType& map) {
    shortWords_.reserve(map.cbegin()->second.size());
    std::copy(map.cbegin()->second.cbegin(), map.cbegin()->second.cend(), std::back_inserter(shortWords_));
    shortWords_.reserve(map.crbegin()->second.size());
    std::copy(map.crbegin()->second.cbegin(), map.crbegin()->second.cend(), std::back_inserter(longWords_));
}

void Counter::print() {
    std::cout << "Characters: " << characterCount_ << '\n';
    std::cout << "Words: " << wordCount_ << '\n';
    std::cout << "Lines: " << lineCount_ << '\n';
    std::cout << "Shortest words, (" << shortWords_.cbegin()->size() << " characters): ";
    std::copy(shortWords_.cbegin(), shortWords_.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nLongest words, (" << longWords_.cbegin()->size() << " characters): ";
    std::copy(longWords_.cbegin(), longWords_.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nRarest words (occurrences:  " << minMaxCounts_.first << "): ";
    std::copy(rareWords_.cbegin(), rareWords_.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\nMost common words (occurrences:  " << minMaxCounts_.second << "): ";
    std::copy(commonWords_.cbegin(), commonWords_.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';
}

// 19 points (only -2 for not readign file using copy and istream iterators)
// Conclusion: 53 EUROFGĄBKI