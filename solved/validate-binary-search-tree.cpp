// OJ: https://leetcode.com/problems/validate-binary-search-tree/
// Author: https://github.com/brawnerquan
// Time: O(n) tree traversal
// Space: O(n) stack
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
    //root can never be null so dont need to check here
    bool isValidBST(TreeNode* root) {
        long last_val = (long)INT_MIN - 1;
        TreeNode *curr_node = root;
        while(curr_node != nullptr or !stack.empty()){
            //keep going until we run out of left nodes
            while(curr_node != nullptr){
                stack.push(curr_node);
                curr_node = curr_node->left;
            }
            //curr_node is null, so we gotta get another node. will be in order as we put all left on the stack first
            curr_node = stack.top();
            stack.pop();

            //if the last value we saw is not less than the next value we just found, we have an invalid BST
            if(!(last_val < curr_node->val))
                return false;

            //otherwise, update last_val and move to the right as we need to go the next bottom left leaf and come back up again
            last_val = curr_node->val;
            curr_node = curr_node->right;
        }
        return true;
    }
private:
    stack<TreeNode *> stack;
};

/*
class Solution {
public:
    //root can never be null so dont need to check here
    bool isValidBST(TreeNode* root) {
        return verifyBST(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
    bool verifyBST(TreeNode *root, long low, long high){
        if(root == nullptr)
            return true;

        //first we make sure the root is valid (within the range)
        if(root->val <= low or root->val >= high)
            return false;
        //if it's in a valid range, recurse and make sure the children are in the range.
        //all left children have to be less than this root and all right children have to be greater than this root
        return verifyBST(root->left, low, root->val) and verifyBST(root->right, root->val, high);
    }
};
*/
