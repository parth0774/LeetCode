#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;
        
        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }
        
        std::string result;
        for (const std::string &row : rows) {
            result += row;
        }
        
        return result;
    }
};
