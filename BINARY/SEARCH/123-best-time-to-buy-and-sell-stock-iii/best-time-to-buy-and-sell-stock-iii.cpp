class Solution {
public:
 int solve(int ind,int buy,vector<int>& prices,vector<vector<vector<int>>>& dp,int n,int profit,int tran)
   
    {if(ind==n || tran==0) return 0;
     if(dp[ind][buy][tran]!=-1) return dp[ind][buy][tran];
        if(buy)
            profit=max(-prices[ind]+ solve(ind+1,0,prices,dp,n,profit,tran),0+ solve(ind+1,1,prices,dp,n,profit,tran));
         else
            profit=max(prices[ind]+ solve(ind+1,1,prices,dp,n,profit,tran-1), solve(ind+1,0,prices,dp,n,profit,tran));
      return dp[ind][buy][tran]=profit;

    }
    int maxProfit(vector<int>& prices) {
        
        int  n=prices.size();
     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
       return solve(0,1,prices,dp,n,0,2);
    }
};