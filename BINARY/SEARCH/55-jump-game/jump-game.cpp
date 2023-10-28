class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),finish=0;
        for(int i=0;i<n;i++)
        {
            if(finish< i) return false;
            finish=max(finish,i+nums[i]);
        }
        return true;
    }
};