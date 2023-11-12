class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++) dp[m-1][j]=triangle[m-1][j];
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j-- )
            {
                 int d=triangle[i][j]+dp[i+1][j];
                 int dg=triangle[i][j]+dp[i+1][j+1];
                 dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];
    }
};