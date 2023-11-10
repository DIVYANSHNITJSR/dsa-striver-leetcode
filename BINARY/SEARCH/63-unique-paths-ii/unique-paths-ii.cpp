class Solution {
public:
    // int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    // {
    //     if(j==0 && i==0)
    //     return 1;
    //     if(i<0 || j<0 || grid[i][j]==1)
    //       return 0;
    //       if(dp[i][j]!=-1)
    //          return dp[i][j];
    //     int up=solve(i-1,j,grid,dp);
    //     int left=solve(i,j-1,grid,dp);
    //     return dp[i][j]=up+left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       
        vector<vector<int>> dp(m,vector<int>(n,-1));
         for(int i=0;i<m;i++)
          {
            for(int j=0;j<n;j++)
            {    
                if(j==0 && i==0 )
                  dp[i][j] = (grid[0][0] == 0) ? 1 : 0;
                 else if(grid[i][j]==1)
                   dp[i][j]=0;
                
                 
                 
                
                else{
                   int up=0,left=0;
                  if(i>0)  up=dp[i-1][j];
                  if(j>0)  left=dp[i][j-1];
                     dp[i][j]=up+left;  
                }
                
            }
          }
          return dp[m-1][n-1];
       
    }
};