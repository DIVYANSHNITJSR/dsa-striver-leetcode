class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[0][i] && grid[0][i]==1)
                dfs(0,i,vis,grid);
            
            if(!vis[m-1][i] && grid[m-1][i]==1)
                dfs(m-1,i,vis,grid);
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,vis,grid);
            
            if(!vis[i][n-1] && grid[i][n-1]==1)
                dfs(i,n-1,vis,grid);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                   count++;
            }
        }
        return count;
    }
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid)
    {
        
        int m=grid.size();
        int n=grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] || grid[row][col] !=1 ) {
            return;
        }
        vis[row][col]=1;
        dfs(row-1,col,vis,grid);
        dfs(row,col+1,vis,grid);
        dfs(row,col-1,vis,grid);
        dfs(row+1,col,vis,grid);
    }
};