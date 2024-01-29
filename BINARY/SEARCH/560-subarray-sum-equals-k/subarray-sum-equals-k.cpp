class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int presum=0;
        int ans=0;
        mp.insert({0,1});
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            if(mp.find(presum-k)!=mp.end())
               {
                   ans+=mp[presum-k];
                  
               }
                mp[presum]++;
        }
        return ans;
    }
};