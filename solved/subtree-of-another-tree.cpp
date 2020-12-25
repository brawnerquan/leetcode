// OJ: https://leetcode.com/problems/subtree-of-another-tree/
// Author: https://github.com/brawnerquan
// Time: O(n * m) cos for each node you might have to check the entire size of the target subtree
// Space: O(n) (recursion depth)
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //if s and t exactly match!
        if(checkSubtree(s, t))
            return true;
        //otherwise we have to keep looking. if either of the subtrees are equal then we're good
        if(s->left != nullptr){
            if(isSubtree(s->left, t))
            return true;
        }
        if(s->right != nullptr){
            if(isSubtree(s->right, t))
            return true;
        }
        return false;
    }
    bool checkSubtree(TreeNode *s, TreeNode *t){
        //trick to save comparisons!
        if(s == nullptr or t == nullptr)
            return s == t;
        if(s->val != t->val)
            return false;
        //otherwise
        return checkSubtree(s->left, t->left) and checkSubtree(s->right, t->right);
    }
};
