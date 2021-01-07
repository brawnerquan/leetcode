// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: https://github.com/brawnerquan
// Time: O(logn/H)
// Space: O(logn/H)
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;

        if(root->val == key){
            TreeNode *original_root = root;
            if(root->left == nullptr and root->right == nullptr){
                delete root;
                return nullptr;
            }else if(root->left == nullptr){
                root = root->right;
            }else if(root->right == nullptr){
                root = root->left;
            }else{
                //if there are two children
                root = root->right;
                //find the leftmost child of the right child
                TreeNode *curr_node = original_root->right;
                while(curr_node->left != nullptr)
                    curr_node = curr_node->left;
                curr_node->left = original_root->left;
            }
            delete original_root;
            return root;
        }


        findandDelete(nullptr, root, key);
        return root;
    }

    void findandDelete(TreeNode *parent, TreeNode *root, int key){
        if(root->val != key){
            if(key < root->val){
                if(root->left != nullptr)
                    findandDelete(root, root->left, key);
            }else{
                if(root->right != nullptr)
                    findandDelete(root, root->right, key);
            }
        }else{//we've found the node to delete
            if(key < parent->val){//if we're a left child
                if(root->left == nullptr and root->right == nullptr){
                    delete root;
                    parent->left = nullptr;
                }else if(root->left == nullptr){
                    parent->left = root->right;
                    delete root;
                }else if(root->right == nullptr){
                    parent->left = root->left;
                    delete root;
                }else{
                    //if there are two children
                    parent->left = root->right;
                    //find the leftmost child of the right child
                    TreeNode *curr_node = root->right;
                    while(curr_node->left != nullptr)
                        curr_node = curr_node->left;
                    curr_node->left = root->left;
                    delete root;
                }


            }else{//if we're a right child
                if(root->left == nullptr and root->right == nullptr){
                    delete root;
                    parent->right = nullptr;
                }else if(root->left == nullptr){
                    parent->right = root->right;
                    delete root;
                }else if(root->right == nullptr){
                    parent->right = root->left;
                    delete root;
                }else{
                    //if there are two children
                    parent->right = root->left;
                    //find the rightmost child of the left node
                    TreeNode *curr_node = root->left;
                    while(curr_node->right != nullptr)
                        curr_node = curr_node->right;
                    curr_node->right = root->right;
                    delete root;
                }
            }
        }
    }


};
