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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
        return NULL;
        else if(root->val>key)
         {
             root->left=deleteNode(root->left,key);
         }
         else if(root->val<key)
           {
               root->right=deleteNode(root->right,key);
           }
        
        else if(root->val==key)
         {
             if(root->left==NULL && root->right==NULL){
                  delete root;
                  return NULL;
                  }
            else if(root->left==NULL)
               {TreeNode* temp=root;
               root=root->right;
               delete temp;
             
               }
               else if(root->right==NULL)
               {TreeNode* temp=root;
               root=root->left;
               delete temp;
             
               }
              else if(root->left  &&  root->right)
                  {  TreeNode* tmp=root->right;
                  while(tmp->left)
                    tmp=tmp->left;
                      root->val=tmp->val;
                      root->right=deleteNode(root->right,root->val);
                  }
         }
        
        
        return root;   
    }
    
   
};