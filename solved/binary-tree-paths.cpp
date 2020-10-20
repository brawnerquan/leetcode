// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: https://github.com/brawnerquan
// Time: O(N) since we visit each node once
// Space: O(?) not sure. should be N recursive calls, one for each node and theres ~ n + 1/2 leaves so idk where that leaves us lol
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> subpaths;
        if(root == nullptr)
            return subpaths;
        //use a pre-order traversal to make paths starting from root first
        string curr_node = to_string(root->val);
       // cout << "CURR NODE: " << curr_node << endl;
        vector<string> left_subpaths = binaryTreePaths(root->left);
        vector<string> right_subpaths = binaryTreePaths(root->right);
        for(int i = 0; i < left_subpaths.size(); i++){
             subpaths.push_back(curr_node + "->" + left_subpaths[i]);
        }
        for(int i = 0; i < right_subpaths.size(); i++){
             subpaths.push_back(curr_node + "->" + right_subpaths[i]);
        }
        if(subpaths.size() == 0)
            subpaths.push_back(curr_node);
        return subpaths;
    }
};