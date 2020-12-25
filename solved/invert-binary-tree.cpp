// OJ: https://leetcode.com/problems/invert-binary-tree/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1)
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
    TreeNode* invertTree(TreeNode* root) {
       if(root == nullptr)
            return root;
        TreeNode *temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        //swap nodes
        return root;
    }
};
