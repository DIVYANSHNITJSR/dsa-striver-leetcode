class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(); // Number of elements in the input vector
        int n = N / 2; // Half the size of the vector
        vector<vector<int>> leftSum(n + 1), rightSum(n + 1); // Two-dimensional vectors to store the sums of subsets

        // Generate all possible subsets of the input vector
        int countLimitMask = ((1 << n) - 1); // Mask to iterate through subsets
        for (int i = 0; i <= countLimitMask; i++) {
            int leftSize = 0; // Number of elements in the current left subset
            int leftSumValue = 0; // Sum of elements in the left subset
            int rightSumValue = 0; // Sum of elements in the right subset

            // Iterate through the binary representation of the subset
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) { // Check if the j-th bit is set in the subset
                    leftSize++;
                    leftSumValue += nums[j]; // Add the j-th element to the left subset sum
                    rightSumValue += nums[j + n]; // Add the (j+n)-th element to the right subset sum
                }
            }

            // Store the sums in the corresponding size vectors
            leftSum[leftSize].push_back(leftSumValue);
            rightSum[leftSize].push_back(rightSumValue);
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of all elements
        int minDifference = min(abs(totalSum - 2 * leftSum[n][0]), abs(totalSum - 2 * rightSum[n][0])); // Calculate the initial minimum difference

        // Sort the rightSum vectors for binary search later
        for (int rightSize = 0; rightSize <= n; rightSize++) {
            sort(rightSum[rightSize].begin(), rightSum[rightSize].end());
        }

        // Iterate through the leftSum vectors
        for (int leftSize = 1; leftSize < n; leftSize++) {
            for (auto &leftSumValue : leftSum[leftSize]) { // Iterate through the subsets of size leftSize in the leftSum vector
                int desiredRightSum = (totalSum - 2 * leftSumValue) / 2; // Calculate the desired sum for the right subset
                int rightSize = n - leftSize; // Calculate the size of the right subset
                auto &rightSums = rightSum[rightSize]; // Get the corresponding rightSum vector

                auto itr = lower_bound(rightSums.begin(), rightSums.end(), desiredRightSum); // Find the lower bound of the desired sum in the rightSum vector
                if (itr != rightSums.end()) { // If a valid sum is found
                    minDifference = min(minDifference, abs(totalSum - 2 * leftSumValue - 2 * (*itr))); // Update the minimum difference if necessary
                }
                if (itr != rightSums.begin()) { // If the lower bound is not the first element
                    itr--; // Move to the previous element
                    minDifference = min(minDifference, abs(totalSum - 2 * leftSumValue - 2 * (*itr))); // Update the minimum difference if necessary
                }
            }
        }

        return minDifference; // Return the minimum difference
    }
};