class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high =nums.size()-1;
        int n=nums.size();
        int mid;
        while (low <=high)
        {
            mid =low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }

            // if left part sorted
          if (nums[low]<=nums[mid])

        {
            if(target>=nums[low]&&target<=nums[mid])
              high=mid-1;
            else
              low=mid+1;
        }
        // if right part sorted
        else

        {
            if(target>=nums[mid]&&target<=nums[high])
              low=mid+1;
            else
              high=mid-1;
        }
        
        }
        return -1;
    }
};