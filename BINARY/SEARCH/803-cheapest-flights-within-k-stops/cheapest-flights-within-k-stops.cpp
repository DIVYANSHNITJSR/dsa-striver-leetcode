class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        // Build the adjacency list
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> pri(n, 1e9); // Initialize with maximum possible value
        pri[src] = 0;
        
        int stops = 0;
        
        queue<pair<int, pair<int, int>>> q; // Queue for BFS
        q.push({0, {src, 0}});
        
        while (!q.empty()) {
            int stop = q.front().first;
            int city = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(stop>k)
            continue;

            for (auto x : adj[city]) {
                int wtprice = x.second;
                int nextcity = x.first;
                
                if (price + wtprice < pri[nextcity]) {
                    pri[nextcity] = price + wtprice;
                    q.push({stop + 1, {nextcity, pri[nextcity]}});
                }
                
                
            }
           
        }
      if(pri[dst]==1e9)  
        return -1;
        return pri[dst];
    }
};


