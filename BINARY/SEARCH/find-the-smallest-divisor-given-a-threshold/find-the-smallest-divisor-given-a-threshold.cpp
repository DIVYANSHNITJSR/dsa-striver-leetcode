class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
     {   int ans=0;
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int mid;
        while (low<=high)
          {
              mid=(low+high)/2;
              if(sum_less_equal_threshold(nums,threshold,mid))
                   {
                       ans=mid;
                       high=mid-1;
                   } 
                   else
                      low=mid+1;
          }
          return ans;
    }
    public:
         bool sum_less_equal_threshold(vector <int>& nums,int threshold,int mid)
         {    int sum=0;
              int low=1;
              int high=*max_element(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]%mid==0)
                         sum=sum+(nums[i]/mid);
                    else
                          sum=sum+(nums[i]/mid)+1;
                    if(sum>threshold)
                    {
                        return false;
                    }
                }
                return true;
         }
};