class Solution {
public:
    void sortColors(vector<int>& nums) 
    {    
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while (mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                mid++;
                low++ ;
            }
            else if(nums[mid]==1)
            {
                   mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
                
            }
        }













    //     int count0=0;
    //     int count1=0;
    //     int count2=0;
    // for(int i=0;i<nums.size();i++)
    //   {
    //       if(nums[i]==0)
    //         ++count0;
    //       else if(nums[i]==1)
    //          ++count1;  // if we write count1++; then some of  the test cases goes wrong.why?
    //        else
    //          ++count2;
    //   }
    //   for (int i=0;i<count0;i++)
    //      {
    //          nums[i]=0;
    //      }
    //      for (int i=count0;i<(count0+count1);i++)
    //      {
    //          nums[i]=1;
    //      }
    //      for (int i=nums.size()-count2;i<nums.size();i++)
    //      {
    //          nums[i]=2;
    //      }
    }
};