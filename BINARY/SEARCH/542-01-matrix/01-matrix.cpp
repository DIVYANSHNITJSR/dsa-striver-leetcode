#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return mat;
        int n = mat[0].size();
        
        using Pair = pair<int, int>;
        queue<Pair> q;
        
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX)); 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        
        while (!q.empty()) {   
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int newR = r + drow[i];
                int newC = c + dcol[i];
                
                if (newR >= 0 && newR < m && newC >= 0 && newC < n) 
                {
                    if (dis[newR][newC] > dis[r][c] + 1) {
                        dis[newR][newC] = dis[r][c] + 1;
                        q.push({newR, newC});
                    }
                }
            }
        }
        
        return dis;
    }
};




