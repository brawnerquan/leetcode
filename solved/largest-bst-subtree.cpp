// OJ: https://leetcode.com/problems/largest-bst-subtree/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n) for recursion and bools
/**
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
    int largestBSTSubtree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        bool isValid = true;
        return largestBSTSubtree(root, INT_MIN, INT_MAX, &isValid);
    }
    int largestBSTSubtree(TreeNode *root, int low, int high, bool *isValid){
        if(root == nullptr)
            return 0;
        //if this bst is invalid, return -1 to mark that the current BST we're building is invalid
        if(root->val <= low or root->val >= high){
            *isValid = false;//mark that this subtree is invalid
            return -1;
        }
        //if we're at a leaf and we're valid, include the leaf in the count
        if(root->left == nullptr and root->right == nullptr)
            return 1;
        //this node is valid. now we must see if it's children continue to build a valid BST OR if there is a bigger BST in any of the children
        bool isLeftValid = true;
        bool isRightValid = true;
        int left_subtree = largestBSTSubtree(root->left, low, min(high, root->val), &isLeftValid);
        int right_subtree = largestBSTSubtree(root->right, max(low, root->val), high, &isRightValid);
        //if either subtree is invalid, mark that this tree is invalid
        if((!isLeftValid or !isRightValid) and isValid != nullptr)
                *isValid = false;
        //if either direct subtree is invalid, search for
        if(!isLeftValid)
            left_subtree = largestBSTSubtree(root->left, INT_MIN, INT_MAX, nullptr);
        if(!isRightValid)
            right_subtree = largestBSTSubtree(root->right, INT_MIN, INT_MAX, nullptr);
        //if either subtree was invalid, we must return the greater subtree
        if(!isLeftValid or !isRightValid)
            return max(left_subtree, right_subtree);
        //otherwise we return the size of this subtree as it is valid!
        return 1 + left_subtree + right_subtree;
    }
};
