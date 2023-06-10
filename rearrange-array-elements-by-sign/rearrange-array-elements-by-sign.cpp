class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
     {
        vector <int> v1;
        vector <int> v2;
        int n=nums.size();
        for (auto it:nums)
        {
            if(it>0)
            v1.push_back(it);
            else if(it<0)
            v2.push_back(it);
        }
        nums.clear();
        int i=0;
        while(nums.size()!=n)
        {
            nums.push_back(v1[i]);
            nums.push_back(v2[i]);
            i++;
        }
        return nums;
    }
};