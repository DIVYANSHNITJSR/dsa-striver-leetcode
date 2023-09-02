class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> vis(numCourses,0);
        vector<vector<int>> adj(numCourses);
       for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
           {
               if(!vis[i])
                 {
                     if(detectCycle(i,adj,vis))
                        return false;
                 }
           }
        
          return true;

    }
    bool detectCycle(int start,vector<vector<int>>& adj,vector<int>& vis )
    {
        // vis[start]=1;
        for(auto it:adj[start])
           {
               if(!vis[it])
                  {   vis[it]=1;
                  if(detectCycle(it,adj,vis))
                      return true;
                  }
                  else if(vis[it]==1)
                    return true;
           }
           vis[start]=2;
           return false;
    }
};