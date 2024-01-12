class Solution {
public:int solve(int i,int j,string& s,string& s1,vector<vector<int>>& dp)
{   if(i<0||j<0)
       return 0;
    if(dp[i][j]!=-1)
       return dp[i][j];

    if(s1[i-1]==s[j-1])
    {
        return dp[i][j]=1+ solve(i-1,j-1,s,s1,dp);
    }
    else
    return dp[i][j]=max(solve(i,j-1,s,s1,dp),solve(i-1,j,s,s1,dp));
}
    int minInsertions(string s) {
        
         string s1=s;
         reverse(s1.begin(),s1.end());
         int n=s.size();
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         for(int i=0;i<=n;i++)
           dp[i][0]=0;
           for(int j=0;j<=n;j++)
           dp[0][j]=0;
            solve(n,n,s,s1,dp);
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    ans=max(ans,solve(i,j,s,s1,dp));
                }
            }
            return n-ans;
    }
};