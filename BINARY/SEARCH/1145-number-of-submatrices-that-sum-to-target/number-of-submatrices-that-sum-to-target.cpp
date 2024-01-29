class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)  {
        int n=matrix.size();
        int m=matrix[0].size();
       
        for(int i=0;i<n;i++)
        {  
            for(int j=1;j<m;j++)
            {
               matrix[i][j]+=matrix[i][j-1];
                 
            }
        }
          int ans=0;
        for(int startcol=0;startcol<m;startcol++)
        {
            for(int j=startcol;j<m;j++)
            {   int cumsum=0;
                unordered_map<int,int> mp;
                mp.insert({0,1});
                for(int i=0;i<n;i++)
                {   cumsum+=matrix[i][j]-(startcol>0?matrix[i][startcol-1]:0);
                     if(mp.find(cumsum-target) != mp.end()) {
                        ans += mp[cumsum - target];
                    }
                    mp[cumsum]++;
                }
            }
            
        }
        return ans;
    }
};