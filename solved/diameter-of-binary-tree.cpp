// OJ: https://leetcode.com/problems/diameter-of-binary-tree/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int long_root_path = 0;
        return max(findMaxDepth(root, &long_root_path), long_root_path);
    }
    int findMaxDepth(TreeNode *root, int *long_root_path){
        int left = 0;
        int right = 0;
        if(root->left != nullptr)
            left = 1 + findMaxDepth(root->left, long_root_path);
        if(root->right != nullptr)
            right = 1 + findMaxDepth(root->right, long_root_path);
        *long_root_path = max(*long_root_path, left + right);
        return max(left, right);
    }
};
