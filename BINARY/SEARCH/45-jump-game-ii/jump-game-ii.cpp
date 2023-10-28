class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;  // If the array has 0 or 1 element, no jumps are needed.

        int maxReach = 0;  // The farthest index you can reach.
        int steps = 0;     // The number of jumps taken.
        int currMax = 0;   // The maximum index that can be reached with the current number of jumps.

        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);  // Update the farthest reachable index.
            if (i == currMax) {
                steps++;       // Take a jump.
                currMax = maxReach;  // Update the maximum reachable index for the next jump.
            }
        }
        return steps;
    }
};
