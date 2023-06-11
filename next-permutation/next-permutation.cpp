class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
        // int n = nums.size();
        // int i = n - 2;
        // while (i >= 0 && nums[i] >= nums[i + 1]) {
        //     i--;
        // }
        // if (i==-1)
        // {  reverse(nums.begin(),nums.end());
        //   return;
        // }int j;
        // int result=0;
        // for (int j=i+1;i<n;j++)
        // {  
        //     if(nums[j]>nums[i]  && nums[j]<result)
        //         {
        //              result=nums[j];

        //         }
        // }
        // int k;
        // for (int k=i+1;k<n;k++)
        //    {
        //        if(nums[k]==result)
        //          break;
        //    }
        // swap(nums[i],nums[k] );
        // sort(nums.begin() + (i + 1), nums.end());
    }
};

