#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using WordSizeMapType = std::map<size_t, std::set<std::string>>;
using WordCounterMapType = std::map<std::string, size_t>;

class Counter {
public:
    Counter(const std::string& filePath);

private:
    void readFromFile(const std::ifstream& inFile);
    void rareCommonWordsFill(const WordCounterMapType& map);
    void shortLongWordsFill(const WordSizeMapType& map);
    void print();
    std::pair<size_t, size_t> minMaxCounts_;
    std::vector<std::string> commonWords_;
    std::vector<std::string> rareWords_;
    std::vector<std::string> longWords_;
    std::vector<std::string> shortWords_;
    size_t characterCount_{0};
    size_t wordCount_{0};
    size_t lineCount_{0};
};
