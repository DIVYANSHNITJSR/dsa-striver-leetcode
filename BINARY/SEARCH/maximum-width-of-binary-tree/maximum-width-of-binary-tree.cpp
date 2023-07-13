/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 typedef unsigned long long int ull;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(root==NULL)
          return 0;
      map<int,pair<int,int>>mp;
        solve( root, mp, 0, 0);
        map<int,pair<int,int>>::iterator it;
        
        int maxWidth = 0;
        
        for(it=mp.begin();it!=mp.end();it++){
            
            int left = it->second.first;
            int right = it->second.second;
            int t = right-left+1;
            maxWidth = max(t,maxWidth);
            
        }
        
      return maxWidth;
    }
    void solve(TreeNode* root,map<int,pair<int,int>>& mp,ull y,ull x)
    {
        if(root==NULL)
          return;
        
       if(mp.find(y)==mp.end())
          mp[y]=make_pair(x,x);
        else{
            pair<int,int> p=mp[y];
            if(p.first>x)
               p.first=x;     //mp.second.first
            if(p.second<x)
               p.second=x;
            mp[y]=p;
        }
    solve (root->left,mp,y+1,2*x+1);
    solve (root->right,mp,y+1,2*x+2);
    }
};