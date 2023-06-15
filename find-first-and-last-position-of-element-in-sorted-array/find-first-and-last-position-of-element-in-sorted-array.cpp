class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int x,y;
      if(binary_search(nums.begin(),nums.end(),target))
      {
           x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
           y=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin()-1;
           return {x,y};
      }

      return {-1,-1};
    }
};