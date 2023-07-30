class Solution {
public:
    int findCircleNum(vector<vector<int>>& con)
     {   int count=0;
        int v=con.size();
        vector<int> vis(v,0);  //vector <int> vis[v]={0};
        for(int i=0;i<v;i++)
          {
              if(!vis[i])
           {
              count++;
               dfs(con,vis,i);
           }
          }
          return count;
    }
    public:
        void dfs( vector<vector<int>>& con,vector<int>& vis,int i)
        {
            vis[i]=1;
            for(int j=0;j<con.size();j++)
               {
                   if(con[i][j]==1 && !vis[j])
                   {
                       dfs(con,vis,j);
                   }
               }
        }
};