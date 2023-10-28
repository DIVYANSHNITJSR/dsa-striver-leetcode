class Solution {
public:
    bool canJump(vector<int>& nums) {
        int gole=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--)
        {  if(i+nums[i]>=gole)
            gole=i;
            if(gole==0)
              return true;
              
        }
        return false;
    }
};