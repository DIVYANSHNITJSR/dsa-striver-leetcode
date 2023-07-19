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
    int kthSmallest(TreeNode* root, int k) {
      int c=0;
       return solve(root,k,c);
        
    }
    public:
       int solve (TreeNode* root,int k,int& c)
       {
            if(root==NULL)
               return 0;
            int leftside=solve(root->left,k,c);
               if(leftside!=0)
                 return leftside;
               c++;
                if(c==k)
                return root->val;
         return solve(root->right,k,c);
                
       }
};