class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    set<int> s;
    for (auto itr : nums) {
        s.insert(itr);
    }

    int count = 0;
    int longest = 0;
    int prev = INT_MIN;

    for (auto num : s) {
        if (num == prev + 1) {
            count++;
        } else {
            count = 1;
        }
        longest = max(longest, count);
        prev = num;
    }

    return longest;
}
};