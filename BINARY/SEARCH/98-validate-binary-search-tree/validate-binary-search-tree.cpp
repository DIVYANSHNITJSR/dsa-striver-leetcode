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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
          return true;
        if(isValidBST(root->right) && isValidBST(root->left) &&Islesser(root->left,root->val)&&Isgreater(root->right,root->val))
        return true;
        return false;
    }
    bool Islesser(TreeNode* root,int & value)
    {
        if(root==NULL)
         return true;
         if(root->val<value   && Islesser(root->left,value) &&Islesser(root->right,value))
         return true;
         return false;
    }
     bool Isgreater(TreeNode* root,int & value)
    {
        if(root==NULL)
         return true;
         if(root->val>value   && Isgreater(root->left,value) &&Isgreater(root->right,value))
         return true;
         return false;
    }
};