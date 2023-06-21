class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Initialize the lower and upper bounds for binary search
        int low = 0;
        int high = arr.size();   //why high is arr.size()?
        //    In the binary search algorithm, the high variable represents the upper bound of the search space. It indicates the index that is one position beyond the last element of the range being considered.
       // Initially, the entire array is considered as the search space, so the lower bound low is set to 0, indicating the first index. To define the upper bound high, we want to indicate the position beyond the last index of the array, which corresponds to arr.size(). This ensures that the search space includes all valid indices in the array.

        // Perform binary search
        while (low < high) {
            // Calculate the middle index
            int mid = low + (high - low) / 2;

            // Check if the difference between arr[mid] and (mid + 1) is less than k
            if (arr[mid] - (mid + 1) < k)
                // If true, update the lower bound to mid + 1
                low = mid + 1;
            else
                // If false, update the upper bound to mid
                high = mid;
        }

        // Return the k-th missing positive integer
        return low + k;
    }
};
