class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        // Build the adjacency list
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> pri(n, INT_MAX); // Initialize with maximum possible value
        pri[src] = 0;
        
        int stops = 0;
        
        queue<pair<int, int>> q; // Queue for BFS
        q.push({src, 0});
        
        while (!q.empty() && stops <= k) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                int city = q.front().first;
                int price = q.front().second;
                q.pop();
                
                for (const auto& neighbor : adj[city]) {
                    int neighborCity = neighbor.first;
                    int neighborPrice = neighbor.second;
                    
                    if (price + neighborPrice < pri[neighborCity]) {
                        pri[neighborCity] = price + neighborPrice;
                        q.push({neighborCity, pri[neighborCity]});
                    }
                }
            }
            
            if (stops == k) {
                break;
            }
            
            ++stops;
        }
        
        return pri[dst] == INT_MAX ? -1 : pri[dst];
    }
};

