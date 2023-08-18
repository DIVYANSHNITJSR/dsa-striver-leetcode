class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue <pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                  {
                       q.push({{i,j},0});
                       vis[i][j]=1;
                  }
                  
            }
        }
        int drow[]={0,-1,0,1};
        int dcol[]={1,0,-1,0};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int  c=q.front().first.second;
            int minDis=q.front().second;
            q.pop();
            dis[r][c]=minDis;
            for(int i=0;i<4;i++)
              {
                  int nrow=r+drow[i];
                  int ncol=c+dcol[i];
                  if(ncol>=0 && ncol<n && nrow>=0 && nrow<m && mat[nrow][ncol]==1 && !vis[nrow][ncol])
                  {    
                          vis[nrow][ncol]=1;
                          q.push({{nrow,ncol},minDis+1});

                      
                  }
              }
        }
        return dis;
    }
};