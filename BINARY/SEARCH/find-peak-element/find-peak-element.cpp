class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low=0;
        int n=nums.size();
        int high =n-1;
        if(nums.empty())
        return -1;
        int mid;
        while (low<high)
        {
            mid=low+(high-low)/2;
            
            if(nums[mid]>nums[mid+1])
                 {
                  high=mid;
                 }
            else
               {  
                   low =mid+1;
               }
            
        }
        return low;
    }
};