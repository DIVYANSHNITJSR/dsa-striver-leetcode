class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
     {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
      int result=solve(n-1,amount,coins,dp);
      if(result>=1e9)
      return -1;
      return result;
    }
    int solve(int ind,int target,vector<int>& coins,vector<vector<int>>& dp)
    {
         if(ind==0)
         {
             if(target%coins[ind]==0) return target/coins[ind];
             return 1e9;
         }
         if(dp[ind][target]!=-1)
         return dp[ind][target];
         int not_take= solve(ind-1,target,coins,dp);
         int take=INT_MAX;
         if(target>=coins[ind])
         take= solve(ind,target-coins[ind],coins,dp)+1;
         return dp[ind][target]=min(take,not_take);
    }
};