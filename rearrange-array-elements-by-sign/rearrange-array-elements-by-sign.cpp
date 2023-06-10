class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
     {   int n=nums.size();
        vector <int> v1(n,0);
        int pos=0;
        int neg=1;
     
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
              {
                  v1[pos]=nums[i];
                  pos=pos+2;
              }
              else if(nums[i]<0)
                {
                    v1[neg]=nums[i];
                    neg=neg+2;
                }
        }
        return v1;
    }
};