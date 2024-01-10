class Solution {
public:
    int solve(int ind,int s2,vector<int>& nums,vector<vector<int>>& dp)
    {  if(ind==0)
    {
          if(s2==0 && nums[0]==0)
    return 2;
          if(s2==0 || s2==nums[0])
          return 1;
          return 0;
    }
    if(dp[ind][s2]!=-1)
       return dp[ind][s2];
      int not_take=solve(ind-1,s2,nums,dp);
      int take=0;
       if(s2>=nums[ind])
      take=solve(ind-1,s2-nums[ind],nums,dp);
      return dp[ind][s2]=(take+not_take);


    }
    int findTargetSumWays(vector<int>& nums, int target)
     {
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++)
        {
           totsum+=nums[i];
        }
        
       
       if((totsum+target)<0 || (totsum+target)%2!=0)  return 0;
       int s2=(totsum+target)/2;
       vector<vector<int>> dp(n,vector<int>(s2+1,-1));
       return solve(n-1,s2,nums,dp);

    }
};