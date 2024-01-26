#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestStrChain(vector<string>& nums) {
        int maxi = 1;
        int n = nums.size();
        vector<int> dp(n, 1);

        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i].size() == nums[j].size() + 1 && isPredecessor(nums[j], nums[i]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

private:
    bool isPredecessor(const string& str1, const string& str2) {
        int i = 0, j = 0;
        int mismatchCount = 0;

        while (i < str1.size() && j < str2.size()) {
            if (str1[i] != str2[j]) {
                if (++mismatchCount > 1) {
                    return false;
                }
                j++;  // Skip the character in the longer string
            } else {
                i++;
                j++;
            }
        }

        return true;
    }
};
