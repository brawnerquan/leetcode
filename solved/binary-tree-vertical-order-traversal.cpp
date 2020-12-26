// OJ: https://leetcode.com/problems/binary-tree-vertical-order-traversal/
// Author: https://github.com/brawnerquan
// Time: O(nlogn)//can be done in n if using a map and then iterating through the map by keeping track of the range of the map
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr)
            return answer;
        map<int, vector<int>> columns;
        pair<TreeNode *, int> curr_node;
        queue.push({root, 0});
        while(!queue.empty()){
            curr_node = queue.front();
            queue.pop();
            columns[curr_node.second].push_back(curr_node.first->val);
            if(curr_node.first->left != nullptr)
                queue.push({curr_node.first->left, curr_node.second - 1});
            if(curr_node.first->right != nullptr)
                queue.push({curr_node.first->right, curr_node.second + 1});
        }
        for(map<int, vector<int>>::iterator iter = columns.begin(); iter != columns.end(); ++iter){
            answer.push_back(iter->second);
        }
        return answer;
    }
private:
    vector<vector<int>> answer;
    queue<pair<TreeNode *, int>> queue;
};
