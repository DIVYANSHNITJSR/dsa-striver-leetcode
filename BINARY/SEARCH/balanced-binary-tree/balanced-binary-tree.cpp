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
    bool isBalanced(TreeNode* root) {
       if(root==NULL)
           return true;
       int h= checkHight(root);
       return h!=-1;
    }
    public:
        int checkHight(TreeNode* root)
           {
                  if(root==NULL)
                     return 0;
                  int HeightLeft=checkHight(root->left);
                  if(HeightLeft==-1)
                     return -1;
                  
                  int HeightRight=checkHight(root->right);
                         if(HeightRight==-1)
                             return -1;
                   if(abs(HeightLeft-HeightRight)>1)
                      return -1;
                
                    return max(HeightLeft,HeightRight)+1;
           }
};