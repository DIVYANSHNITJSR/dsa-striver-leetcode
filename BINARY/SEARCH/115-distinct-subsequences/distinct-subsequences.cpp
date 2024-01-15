class Solution {
public:
int solve(int n,int m,string& s,string& t,vector<vector<int>>& dp)
{   if(m==0)return 1;
    if(n==0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    if(s[n-1]==t[m-1])
      return dp[n][m]=solve(n-1,m-1,s,t,dp)+solve(n-1,m,s,t,dp);
      else
       return dp[n][m]=solve(n-1,m,s,t,dp);
}
    int numDistinct(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,t,dp);


    }
};