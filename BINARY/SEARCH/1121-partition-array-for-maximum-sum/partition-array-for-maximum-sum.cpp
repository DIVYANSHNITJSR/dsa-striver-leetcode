class Solution {
public:
int solve(int i,vector<int>& arr,int k,vector<int>& dp)
{int n=arr.size();
if(i==n)  return 0;
if(dp[i]!=-1) return dp[i];
int len=0;
int maxans=INT_MIN;
int maxi=INT_MIN;
    for(int j=i;j<min(n,i+k);j++)
    {   len++;
        maxi=max(maxi,arr[j]);
        int value=maxi*len+solve(j+1,arr,k,dp);
        maxans=max(maxans,value);

    }
    return dp[i]=maxans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {   
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};