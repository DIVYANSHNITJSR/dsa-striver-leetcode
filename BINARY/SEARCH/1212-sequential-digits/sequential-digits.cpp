class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1;i<9;i++)
         q.push(i);
         vector<int> ans;
         while(!q.empty())
         {
             int cur=q.front();
             q.pop();
             if(cur>=low && cur<=high)
               ans.push_back(cur);
             int last_number=cur%10;
             if(last_number+1<=9)
             q.push(cur*10+(last_number+1));
         }
         return ans;
    }
};