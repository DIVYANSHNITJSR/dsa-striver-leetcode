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
        int count = 0;
        return solve(root, k, count);
    }
    
private:
    int solve(TreeNode* root, int k, int& count) {
        if (root == NULL)
            return -1; // Return an invalid value to indicate kth smallest not found
        
        // Traverse left subtree
        int leftResult = solve(root->left, k, count);
        
        // If kth smallest element found in the left subtree, return the result
        if (leftResult != -1)
            return leftResult;
        
        // Increment count for the current node
        count++;
        
        // If count becomes equal to k, we found the kth smallest element
        if (count == k)
            return root->val;
        
        // Otherwise, traverse right subtree
        return solve(root->right, k, count);
    }
};
