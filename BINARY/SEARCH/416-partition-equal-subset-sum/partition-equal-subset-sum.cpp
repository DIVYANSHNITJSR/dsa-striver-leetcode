class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr)
{
   vector<vector<bool>> dp(n+1,vector<bool>(k+1));
   for(int i=0;i<n;i++)
      dp[i][0]=true;
    for(int i=1;i<k;i++)
      dp[0][k]=false;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=k;j++)
          {
               dp[i][j] = dp[i - 1][j];
               if (arr[i - 1] <= j) {
                 dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
               }
          }
      }
   return dp[n][k];


   

}
    bool canPartition(vector<int>& arr) 
    {
        int n=arr.size();
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum=total_sum+arr[i];
        }
        int target =total_sum/2;
        if(total_sum%2!=0)return false;
         
        return subsetSumToK( n,  target,arr);
    }
};