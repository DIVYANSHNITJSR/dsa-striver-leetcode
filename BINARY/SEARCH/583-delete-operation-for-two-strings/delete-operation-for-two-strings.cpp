class Solution {
public:
    int solve(int i,int j,string& s,string& s1,vector<vector<int>>& dp)
{   if(i<0||j<0)
       return 0;
    if(dp[i][j]!=-1)
       return dp[i][j];

    if(s[i-1]==s1[j-1])
    {
        return dp[i][j]=1+ solve(i-1,j-1,s,s1,dp);
    }
    else
    return dp[i][j]=max(solve(i,j-1,s,s1,dp),solve(i-1,j,s,s1,dp));
}
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n1;i++)
        dp[i][0]=0;
        for(int j=0;j<=n2;j++)
        
            dp[0][j]=0;
     
   int ans= solve(n1,n2,word1,word2,dp);
     
 
    int final_result=word1.size() + word2.size() - 2 * ans;
    return final_result;
     }
};