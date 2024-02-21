class Solution {
public:
int findIndex(vector<int>& nums2,int key)
     {
         int n2=nums2.size();
         for(int i=0;i<n2;i++)
         {
             if(nums2[i]==key)
               return i;
         }
         return -1;
     }
   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int n1=nums1.size();
         int n2=nums2.size();
         vector<int> ans;
         for(int i=0;i<n1;i++)
         {   int val=-1;
             int key=nums1[i];
             int index=findIndex(nums2,key);
             for(int j=index+1;j<n2;j++)
             {
                 if(nums2[j]>key)
                    {
                       val=nums2[j];
                        break;
                    }
                    
             }
             ans.push_back(val);
         }
         return ans;
    }
};