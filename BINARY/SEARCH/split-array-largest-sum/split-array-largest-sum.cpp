class Solution {
public:
    int splitArray(vector<int>& nums, int k)
     {   int ans=-1;
        int low=*min_element (nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size();i++)
          {
               high =high +nums[i];

          }
          while (low<=high)
          {
             int mid=(low+high)/2;
              if(lagest_sum_is_min(nums,mid,k))
                 {ans=mid;
                 high=mid-1;
                 }
              else
                  low=mid+1;
          }
          return ans;
    }
    public:
         bool lagest_sum_is_min(vector <int>& nums,int mid,int k)
            {
                int sum=0;
                int count =1;
                for (int i=0;i<nums.size();i++)
                   {
                       if(nums[i]>mid)
                          return false;
                          sum=sum+nums[i];
                       if( sum>mid)
                       {
                           sum=nums[i];
                           count++;
                       }
                   }
                   return count<=k;
            }







};