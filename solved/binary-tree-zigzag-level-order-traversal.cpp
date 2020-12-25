// OJ: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return answer;
        quack.push_back(root);
        TreeNode *curr_node;
        int depth = 0;
        int size;
        //just a boolean we can use to swap between pushing to the front and the back and popping from the front and the back
        bool push_back = true;
        while(!quack.empty()){
            size = quack.size();
            vector<int> curr_level(size);
            //pushing to back, so pop from front
            if(push_back){
                for(int i = 0; i < size; ++i){
                    curr_node = quack.front();
                    quack.pop_front();
                    curr_level[i] = curr_node->val;
                    if(curr_node->left != nullptr)
                        quack.push_back(curr_node->left);
                    if(curr_node->right != nullptr)
                        quack.push_back(curr_node->right);
                }
            }else{//pushing to front so pop from back
                for(int i = 0; i < size; ++i){
                    curr_node = quack.back();
                    quack.pop_back();
                    curr_level[i] = curr_node->val;
                    if(curr_node->right != nullptr)
                        quack.push_front(curr_node->right);
                    if(curr_node->left != nullptr)
                        quack.push_front(curr_node->left);
                }
            }
            answer.push_back(curr_level);
            push_back = !push_back;
            ++depth;
        }
        return answer;
    }
private:
    vector<vector<int>> answer;
    list<TreeNode*> quack;
};
