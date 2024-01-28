class Solution {
public:
    
bool isPalindrome(string& s,int i,int j) {
 

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }

       
        i++;
        j--;
    }

    return true;
}
  int solve(int i,int j,string& s,vector<vector<int>>& dp)
{   if(dp[i][j]!=-1)return dp[i][j];
    if(i>=j)return dp[i][j]=0;
    if(isPalindrome(s,i,j)==true) return dp[i][j]=0;
    int mini=1e9;
 
    for(int k=i;k<j;k++)
      {if(isPalindrome(s,i,k)==false)  continue;
          int cost=1+solve(k+1,j,s,dp);
          mini=min(mini,cost);
      }

   return dp[i][j]=mini;
}
    int minCut(string s) {
        int n=s.size();
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
     return solve(0,n-1,s,dp);

    }
};
// class Solution {
// public:
    
//     bool isPalindrome(string &s, int start, int end) {
        
//         while(start < end) {
            
//             if(s[start] != s[end]) return false;
            
//             start += 1;
//             end -= 1;
            
//         }
        
//         return true;
        
//     }
    
//     int solve(string &s, int start, int end,vector<vector<int>> &dp) {
        
//         if(dp[start][end] != -1) return dp[start][end];
        
//         if(start >= end) return dp[start][end] = 0 ;
        
//         if(isPalindrome(s,start,end) == true)
//             return dp[start][end] = 0;
        
//         int ans = INT_MAX;
        
//         for(int ctr = start ; ctr < end ; ctr ++ ) {
            
//             if(isPalindrome(s,start,ctr)==false)
//                 continue;
            
//             int tempAns = solve(s,start,ctr,dp) + solve(s,ctr+1,end,dp) + 1;
            
//             if(tempAns < ans) ans = tempAns;
//         }
        
//         return dp[start][end] = ans;
        
//     }
    
//     int minCut(string s) {
//         vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
//         return solve(s,0,s.length()-1,dp);
//     }
// };