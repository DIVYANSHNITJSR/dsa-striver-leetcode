class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(graph,color,i)==false)
                return false;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph,vector<int>& color,int start)
    {
        
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            for(auto it:graph[current])
            {
                if(color[it]==-1)
                {   q.push(it);
                    color[it]=!color[current];
                }
                else if(color[it]==color[current])
                    return false;
            }
        }
        return true;
    }
};