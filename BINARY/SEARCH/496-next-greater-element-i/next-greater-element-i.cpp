class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> mp;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--)
        {
             if(s.empty())
               mp[nums2[i]]=-1;
              else if(!s.empty())
              {
                  if(s.top()>nums2[i])
                     mp[nums2[i]]=s.top();
                  else if(s.top()<=nums2[i])
                  {
                      while(s.size()>0 && s.top()<=nums2[i])
                      s.pop();
                      if(s.size()==0)
                       mp[nums2[i]]=-1;
                      else if(s.top()>nums2[i])
                        mp[nums2[i]]=s.top();
                  }
              }
              s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back(mp[nums1[i]]);
        return ans;
    }
};