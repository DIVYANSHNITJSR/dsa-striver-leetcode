#include <vector>

class Solution {
public:
    std::vector<int> getGoodIndices(std::vector<std::vector<int>>& variables, int target) {
        std::vector<int> result;
        for (int i = 0; i < variables.size(); ++i) {
            int ai = variables[i][0];
            int bi = variables[i][1];
            int ci = variables[i][2];
            int mi = variables[i][3];
            int base = 1;
            for (int j = 0; j < bi; ++j) {
                base = (base * ai) % 10;
            }
            int formula_result = 1;
            for (int j = 0; j < ci; ++j) {
                formula_result = (formula_result * base) % mi;
            }
            if (formula_result == target) {
                result.push_back(i);
            }
        }
        return result;
    }
};