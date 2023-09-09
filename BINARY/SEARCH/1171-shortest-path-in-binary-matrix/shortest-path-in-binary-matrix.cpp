class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     
      int n=grid.size();
      vector<vector<int>> dist(n,vector<int>(n,1e9));
      queue<pair<int,pair<int,int>>> q;
      q.push({0,{0,0}});
     if(n==1 && grid[0][0]==0)
      return 1;
     if(grid[0][0]==0)
     { dist[0][0]=0;
      while(!q.empty())
      {
          int dr[]={0,-1,0,1,1,1,-1,-1};
          int dc[]={-1,0,1,0,1,-1,1,-1};
          auto it=q.front();
          q.pop();
          int dis=it.first;
          int r=it.second.first;
          int c=it.second.second;
          for(int i=0;i<8;i++)
          {
              int nrow=r+dr[i];
              int ncol=c+dc[i];
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 &&dis+1<dist[nrow][ncol])
             { dist[nrow][ncol]=dis+1;
              if(nrow==n-1 && ncol==n-1)
              return dis+2;
              q.push({dis+1,{nrow,ncol}});
             }
          }
      }
     }
      return -1;
    }
};