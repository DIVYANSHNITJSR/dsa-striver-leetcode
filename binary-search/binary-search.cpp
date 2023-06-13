class Solution {
public:
    int search(vector<int>& nums, int target)
     {int n=nums.size();
          int low=0;
          int high=n-1;
          int mid;
          while (low<=high)
          { mid=((high-low)/2)+low;
              if(nums[mid]==target)
                return mid;
              else if(nums[mid]<target)
                     low=mid+1;
            else 
                high=mid-1;
             
          }
          return -1;
    }
};