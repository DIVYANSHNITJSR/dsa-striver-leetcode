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
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> q;
        if(root==NULL)
           return true;
        q.push(root);
        q.push(root);
        while(!q.empty())
         {
            TreeNode* node1=q.front();
            q.pop();
            TreeNode* node2=q.front();
            q.pop();
            
            if(node1==NULL && node2==NULL)
                {
                    continue;
                }
                if((node1==NULL && node2!=NULL)||(node2==NULL &&node1!=NULL))
{
     return false;
}
if(node1->val!=node2->val)
   return false;


            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push (node2->left);
         }
         return true;
    }
};