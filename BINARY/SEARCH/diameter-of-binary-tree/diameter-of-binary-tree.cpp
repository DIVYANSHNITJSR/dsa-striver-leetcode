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
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root->right==NULL&&root->left==NULL)
        //    return 1;
        int res=INT_MIN;
        int u= solve(root,res);
        return res-1;
    }
     public:
         int solve(TreeNode* root,int& res)
          { if(root==NULL)
              return 0;
              int l=solve(root->left,res);
              int r=solve(root->right,res);
              int temp=max(l,r)+1;
              int ans=max(temp,r+l+1);
               res=max(res,ans);
              return temp;
          }

};