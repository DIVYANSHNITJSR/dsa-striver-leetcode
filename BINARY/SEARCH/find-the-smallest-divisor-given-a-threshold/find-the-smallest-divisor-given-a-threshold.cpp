class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = 0; // Variable to store the smallest divisor
        int low = 1; // Lower bound of the binary search range
        int high = *max_element(nums.begin(), nums.end()); // Upper bound of the binary search range, initialized with the maximum element in 'nums'
        int mid;

        while (low <= high) { // Binary search loop
            mid = (low + high) / 2; // Calculate the middle value of the binary search range

            // Check if the sum of divisions using 'mid' is less than or equal to the threshold
            if (sum_less_equal_threshold(nums, threshold, mid)) {
                ans = mid; // Update 'ans' to store the current 'mid' value
                high = mid - 1; // Update the upper bound to search for smaller divisors
            } else {
                low = mid + 1; // Update the lower bound to search for larger divisors
            }
        }

        return ans; // Return the smallest divisor
    }

    bool sum_less_equal_threshold(vector<int>& nums, int threshold, int mid) {
        int sum = 0; // Variable to store the sum of divisions

        // Iterate through the 'nums' vector
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % mid == 0)
                sum = sum + (nums[i] / mid); // If 'mid' evenly divides 'nums[i]', add the division result to 'sum'
            else
                sum = sum + (nums[i] / mid) + 1; // Otherwise, add the division result plus 1 to 'sum' (to account for the remainder)

            // Check if the sum exceeds the threshold
            if (sum > threshold) {
                return false; // Return false if the sum is greater than the threshold
            }
        }

        return true; // Return true if the sum is less than or equal to the threshold
    }
};
