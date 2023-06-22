class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int ans = -1; // Variable to store the minimum maximum sum
        int low = *min_element(nums.begin(), nums.end()); // Set the lowest possible sum as the minimum element in nums
        int high = 0; // Set the highest possible sum as 0 initially

        // Calculate the total sum of all elements in nums
        for (int i = 0; i < nums.size(); i++) {
            high += nums[i];
        }

        // Binary search to find the optimal value
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle value

            // Check if the largest sum is at most mid by calling the largest_sum_is_min function
            if (largest_sum_is_min(nums, mid, k)) {
                ans = mid; // Update the minimum maximum sum
                high = mid - 1; // Adjust the high value to continue searching for a smaller value
            } else {
                low = mid + 1; // Adjust the low value to continue searching for a larger value
            }
        }

        return ans; // Return the minimum maximum sum
    }

private:
    bool largest_sum_is_min(vector<int>& nums, int mid, int k) {
        int sum = 0; // Variable to track the current sum
        int count = 1; // Variable to track the count of subarrays

        // Iterate through the elements of nums
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) {
                return false; // If any element is greater than mid, it is not possible to partition the array into k subarrays
            }

            sum += nums[i]; // Add the current element to the sum

            if (sum > mid) {
                sum = nums[i]; // Reset the sum to the current element
                count++; // Increment the count of subarrays
            }
        }

        return count <= k; // Return true if all elements can be partitioned into at most k subarrays with a maximum sum of mid
    }
};
