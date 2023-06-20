class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;  // Variable to store the final answer
        int low = 1;  // Minimum possible ship capacity
        int high = 1e9;  // Upper bound for ship capacity
        
        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2;  // Calculate the middle value
            
            // Check if the current middle value satisfies the conditions
            if (min_capacity_ship(weights, mid, days)) {
                ans = mid;  // Update the answer to the current middle value
                high = mid - 1;  // Search for a smaller ship capacity
            } else {
                low = mid + 1;  // Search for a larger ship capacity
            }
        }
        
        return ans;  // Return the minimum ship capacity required
    }

private:
    bool min_capacity_ship(vector<int>& weights, int mid, int days) {
        int needed_day = 1;  // Number of days needed to ship the weights
        int sum = 0;  // Current sum of weights on the ship
        
        // Iterate over the weights vector
        for (int i = 0; i < weights.size(); i++) {
            // Check if the weight is greater than the ship capacity
            if (weights[i] > mid) {
                return false;  // Weight cannot be shipped, return false
            }
            
            // Check if adding the weight exceeds the ship capacity
            if (sum + weights[i] > mid) {
                needed_day++;  // Increment the number of days needed
                sum = weights[i];  // Start a new day with the current weight
            } else {
                sum += weights[i];  // Add the weight to the current day's shipment
            }
        }
        
        // Check if the total number of days needed is less than or equal to the given days
        if (needed_day <= days) {
            return true;  // Weights can be shipped within the given days
        } else {
            return false;  // Weights cannot be shipped within the given days
        }
    }
};
