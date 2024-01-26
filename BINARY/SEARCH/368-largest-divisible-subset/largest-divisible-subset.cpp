class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
     {
            vector<int> ans;
            int lastind=0;
            int maxi=1;
            int n=nums.size();
            vector<int> dp(n,1);
            vector<int> hash(n);
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++)
            {    hash[i]=i;
                for(int j=0;j<i;j++)
                {
                    if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                      {
                        
                           dp[i]=1+dp[j];
                            hash[i]=j;
                          
                      }
                }
                if(dp[i]>maxi)
                {
                    maxi=dp[i];
                    lastind=i;
                }
            }
         
            ans.push_back(nums[lastind]);
            while(hash[lastind]!=lastind)
            {  lastind=hash[lastind];
                ans.push_back(nums[lastind]);
              
            }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};