class Solution {
public:
    int solve(int i,int k,int target,vector<vector<int>>& dp)
    {    if(target<0) return 0;
         if(i==0)  return target==0;
          int modulo=1e9+7;
       int ways=0;
        if(dp[i][target]!=-1) return dp[i][target];
        for(int face=1;face<=k;face++)
        {
            ways=(ways+solve(i-1,k,target-face,dp))%modulo;
        }
        return dp[i][target]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
         
       return solve(n,k,target,dp);
       
    }
};