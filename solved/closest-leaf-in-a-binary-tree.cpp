// OJ: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/
// Author: https://github.com/brawnerquan
// Time: O(n) only go through the tree once (ya you revisit when going back up to find the closest leaf a little but you would have had to anyways)
// Space: O(n) for the recursion stack
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
    int findClosestLeaf(TreeNode* root, int k) {
        if(root == nullptr)
            return 0;
        return findNode(root, &k).first;
    }

    pair<int,int> findNode(TreeNode* root, int *k){
        pair<int,int> alt_leaf = {INT_MAX, INT_MAX};
        pair<int,int> main_leaf;


        if(root->val == *k){
            *k = 0;
            return findClosestLeaf(root);
        }

        if(root->left == nullptr and root->right == nullptr)
            return {INT_MAX - 10000, INT_MAX - 10000};

        //either find k in left and calculate the closest leaf on the right
        if(root->left != nullptr){
            main_leaf = findNode(root->left, k);
            //if k was found, the value will not be INT_MAX, and we must now calculate the closest leaf on the right to see if we can beat
            if(main_leaf.first != INT_MAX - 10000){
                alt_leaf = findClosestLeaf(root->right);
                alt_leaf.second += ++*k + 1;
                if(main_leaf.second > alt_leaf.second)
                    return alt_leaf;
                return main_leaf;
            }
            //if K wasn't found then we just discard this
        }

        alt_leaf = {INT_MAX, INT_MAX};

        //or find k in right and calcualte the closest leaf on the left
        if(root->right != nullptr){
            main_leaf = findNode(root->right, k);
            //if k was found, the value will not be INT_MAX, and we must now calculate the closest leaf on the left to see if we can beat
            if(main_leaf.first != INT_MAX - 10000){
                alt_leaf = findClosestLeaf(root->left);
                alt_leaf.second += ++*k + 1;
                if(main_leaf.second > alt_leaf.second)
                    return alt_leaf;
                return main_leaf;
            }
            //if K wasn't found then we just discard this
        }
        return {INT_MAX - 10000, INT_MAX - 10000};
    }

    pair<int, int> findClosestLeaf(TreeNode *root){
        if(root == nullptr)
            return {INT_MAX - 10000,INT_MAX - 10000};

        if(root->left == nullptr and root->right == nullptr)
            return {root->val, 0};

        pair<int,int> left = findClosestLeaf(root->left);
        pair<int,int> right = findClosestLeaf(root->right);

        if(left.second == INT_MAX - 10000){
            ++right.second;
            return right;
        }else if(right.second == INT_MAX - 10000){
            ++left.second;
            return left;
        }else{
            if(++left.second < ++right.second)
                return left;
            return right;
        }
    }

};
