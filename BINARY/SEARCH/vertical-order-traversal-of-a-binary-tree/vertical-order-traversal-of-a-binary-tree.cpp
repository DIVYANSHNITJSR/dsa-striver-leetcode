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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {   
        // Create a vector to store the vertical traversal result
        vector<vector<int>> ans;
        
        // Create a map to store nodes based on their x and y coordinates
        // Use multiset to automatically sort the values at each coordinate
        map<int, map<int, multiset<int>>> mp;
        
        // Call the traverse function to populate the map
        traverse(root, 0, 0, mp);
        
        // Iterate over the map to collect the values in the correct order
        for (auto p : mp)
        {
            vector<int> col;
            
            // Iterate over the multiset at each coordinate to get sorted values
            for (auto q : p.second)
            {
                // Insert all the values from the multiset into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            
            // Add the column vector to the result
            ans.push_back(col);
        }
        
        // Return the vertical traversal result
        return ans;
    }

public:
     // Recursive helper function to traverse the binary tree and populate the map
     void traverse(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& mp)
     {
         // Base case: if root is nullptr, return
         if (root == nullptr)
            return;
        
        // Insert the value of the current node into the map at the appropriate coordinates
        mp[x][y].insert(root->val);
        
        // Recursively traverse the left and right subtrees, adjusting the coordinates accordingly
        traverse(root->left, x - 1, y + 1, mp);
        traverse(root->right, x + 1, y + 1, mp);
     }
};
