class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        { sum=sum+nums[i];
            if(sum>maxi)
              maxi=sum;
             if (sum<0)
              sum=0;
        }  
        if (maxi<0)
          {
            for(int i=0;i<nums.size();i++)
              if(maxi<nums[i])
                 maxi=nums[i];
          }

        return maxi;
    }
};