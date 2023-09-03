class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> ans;
        vector<int> check(n,0);
        for(int i=0;i<n;i++)
          {
              if(!vis[i])
                {
                   detectCycle(i,vis,graph,pathvis,check);
                }
            
          }
          for(int i=0;i<n;i++)
          {
              if(check[i]==1)
                ans.push_back(i);
          }
        
          return ans;
    }

    bool detectCycle(int start,vector<int>& vis,vector<vector<int>>& graph,vector<int>& pathvis,vector<int>& check)
 {
      vis[start]=1;
      pathvis[start]=1;
      check[start]=0;
      for(auto it:graph[start])
      {
          if(!vis[it])
             {
               
                 if(detectCycle(it,vis,graph,pathvis,check))
                    return true;
             }
             else if(pathvis[it]==1)
                return true;
      }
      check[start]=1;
      pathvis[start]=0;
      return false;
}
};