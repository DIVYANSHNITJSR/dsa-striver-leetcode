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
    void preorderTraversal(TreeNode* root, vector<int>& output) {
        if (root == nullptr) {
            return;
        }
        
        output.push_back(root->val);  // Visit the root
        
        preorderTraversal(root->left, output);   // Traverse the left subtree
        
        preorderTraversal(root->right, output);  // Traverse the right subtree
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        preorderTraversal(root, output);
        return output;
    }
};
