class Solution {
public:
    int solve(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp,int n,int profit)
   
    {if(ind==n) return 0;
     if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
            profit=max(-prices[ind]+ solve(ind+1,0,prices,dp,n,profit),0+ solve(ind+1,1,prices,dp,n,profit));
         else
            profit=max(prices[ind]+ solve(ind+1,1,prices,dp,n,profit), solve(ind+1,0,prices,dp,n,profit));
      return dp[ind][buy]=profit;

    }
    int maxProfit(vector<int>& prices)
     {
        int  n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
       return solve(0,1,prices,dp,n,0);
    }
};