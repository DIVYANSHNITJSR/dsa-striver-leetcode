class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int first = -1;
        int second = -1;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                first = mid;
                high = mid - 1;
            }
        }
        
        if (first != -1) {
            int ans = first;
            
            while (ans < nums.size() && nums[ans] == target) {
                second = ans;
                ans++;
            }
        }
        
        return {first, second};
    }
};
