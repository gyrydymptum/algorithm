#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using WordSizeMapType = std::map<size_t, std::set<std::string>>;
using WordCounterMapType = std::map<std::string, size_t>;

class Counter {
public:
    Counter(const std::string& filePath);

private:
    void readFromFile(const std::ifstream& inFile);
    std::pair<size_t, size_t> rareCommonWordsFill(const WordCounterMapType& map);
    void print();
    WordSizeMapType wordSizeMap_;
    std::pair<size_t, size_t> minMaxCounts_;
    std::vector<std::string> commonWords_;
    std::vector<std::string> rareWords_;
    size_t characterCount_{0};
    size_t wordCount_{0};
    size_t lineCount_{0};
};
