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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int level;
        vector <int> v;
        int h=hight(root);
        for(level=0;level<h;level++)
        {
              vector <int> v;
               traversal (root,level,v);
                  if(level%2==0)
                   ans.push_back(v);
                  else
                    {reverse(v.begin(),v.end());
                     ans.push_back(v);
                    }
        }
        return ans;
    }
    public:
        int hight(TreeNode* root)
           {    if(root==NULL)
                   return 0;
               int l=hight(root->left);
               int r=hight(root->right);
               return max(l,r)+1;
           }
        void traversal (TreeNode* root,int level,vector <int>& v)
        {
            if(root==NULL)
               return;
            if(level==0)
            v.push_back(root->val);
            if(level>0)
            {
                traversal(root->left,level-1,v);
                traversal(root->right,level-1,v);
            }
        }
};