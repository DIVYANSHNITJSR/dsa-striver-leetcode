class Solution {
public:
int solve(int n,int m,string& word1,string& word2,vector<vector<int>>& dp)
{
    if(n==0)return m;
    if(m==0)return n;
    if(dp[n][m]!=-1)return dp[n][m];
    if(word1[n-1]==word2[m-1]) return dp[n][m]=solve(n-1,m-1,word1,word2,dp);
    return dp[n][m]=1+min(solve(n-1,m-1,word1,word2,dp),min(solve(n-1,m,word1,word2,dp),solve(n,m-1,word1,word2,dp)));
}
    int minDistance(string word1, string word2) 
    {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1,word2,dp);
    }
};