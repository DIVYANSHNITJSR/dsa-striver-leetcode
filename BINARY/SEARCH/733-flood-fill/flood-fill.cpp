class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector <vector<int>> ans=image;
         int initialColor=image[sr][sc];
         image[sr][sc]=color;
         int drow[]={-1,0,+1,0};
         int dcol[]={0,+1,0,-1};
         dfs(image,ans,initialColor,drow,dcol,color,sr,sc);
         return ans;
    }
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int initialColor,int drow[],int dcol[],int color,int row,int col)
    {   int nrow,ncol;
        ans[row][col]=color;
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<4;i++)
        {
            nrow=row+drow[i];
            ncol=col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]!=color && image[nrow][ncol]==initialColor)
            {
                dfs(image,ans,initialColor,drow,dcol,color,nrow,ncol); 
           }

        }
    }
};