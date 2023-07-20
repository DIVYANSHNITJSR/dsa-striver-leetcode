/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
          return NULL;
        if(root==p||root==q)
           return root; 


       TreeNode* leftside= lowestCommonAncestor(root->left,p,q);
       TreeNode* rightside=lowestCommonAncestor(root->right,p,q);
       if(!leftside && rightside)
            return rightside;
     
       if(leftside && rightside)
            return root;
            return leftside;
    }
 
};