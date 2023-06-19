class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int min_day = -1; // Initialize min_day to -1
        int low = *min_element(bloomDay.begin(), bloomDay.end()); // Find the minimum element in bloomDay and assign it to low
        int high = *max_element(bloomDay.begin(), bloomDay.end()); // Find the maximum element in bloomDay and assign it to high

        while (low <= high) { // Binary search loop: continue while low is less than or equal to high
            int mid = low + (high - low) / 2; // Calculate the midpoint

            // Check if bouquets can be formed for the current mid value
            if (bouquets_formed(bloomDay, m, k, mid)) {
                min_day = mid; // Update min_day to the current mid value
                high = mid - 1; // Adjust the search space to the lower half
            } else {
                low = mid + 1; // Adjust the search space to the upper half
            }
        }

        return min_day; // Return the minimum number of days required
    }

private:
    bool bouquets_formed(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0; // Count of formed bouquets
        int flowers = 0; // Count of consecutive bloomed flowers

        // Iterate through bloomDay
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) { // If the bloom day is less than or equal to the current day
                flowers++; // Increment the count of consecutive bloomed flowers
                if (flowers == k) { // If k consecutive flowers have bloomed
                    bouquets++; // Increment the count of formed bouquets
                    flowers = 0; // Reset the count of consecutive bloomed flowers
                }
            } else {
                flowers = 0; // Reset the count of consecutive bloomed flowers
            }
        }

        return bouquets >= m; // Return true if the count of formed bouquets is greater than or equal to m
    }
};
