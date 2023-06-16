class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int ans=INT_MAX;
        int low=0;
        int n=nums.size();
        int high =n-1;
        int mid;
        while(low <=high)
        {
            mid=(low+high)/2;
            if(nums[mid]<ans)
              ans=nums[mid];
          if(nums[low]<=nums[mid])
          {
              ans=min(ans,nums[low]);
              low=mid+1;
          }
          else 
          {
              ans=min(ans,nums[mid]);
              high=mid-1;
          }



        }
        return ans;
    }
};