#include <string>
#include <map>
#include <set>
#include <sstream>

using WordMapType = std::map<size_t, std::set<std::string>>;

class Counter {
    public:
    Counter(const std::string& filePath);

    private:
    void calculate();
    void print();
    std::stringstream ss_;
    std::string fileContent_;
    WordMapType wordMap_;
    size_t characterCount_ {0};
    size_t wordCount_ {0};
    size_t lineCount_ {0};
};
