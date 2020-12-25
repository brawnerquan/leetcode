// OJ: https://leetcode.com/problems/boundary-of-binary-tree/
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return answer;

        answer.push_back(root->val);

        if(root->left == nullptr and root->right == nullptr)
            return answer;

        find_boundary(root->left, true, false);
        find_boundary(root->right, false, true);
        return answer;
    }

    void find_boundary(TreeNode *root, bool isLeftBoundary, bool isRightBoundary){
        if(root == nullptr)
            return;

        //add leaves as if we're here in the traversal it's time to add right away
        if(root->left == nullptr and root->right == nullptr){
            answer.push_back(root->val);
            return;
        }
        //add left boundary nodes as found as we need them in clockwise order and we visit these first in the correct order
        if(isLeftBoundary)
            answer.push_back(root->val);
        //now recurse on left and right, correctly marking whether or not the child is a boundary node
        //sidenote- checking if root left and right are nullptr arent actually necessary but may? speed up runtime.. not sure though
        find_boundary(root->left, root->left != nullptr and isLeftBoundary, root->right == nullptr and isRightBoundary);
        find_boundary(root->right, root->left == nullptr and isLeftBoundary, root->right != nullptr and isRightBoundary);

        //since we want to add right boundary nodes from the bottom up, we add them after recursing
        if(isRightBoundary)
            answer.push_back(root->val);
    }
private:
    vector<int> answer;
};



/*solution that divides the problem into 3 subtasks
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return answer;

        answer.push_back(root->val);

        if(root->left == nullptr and root->right == nullptr)
            return answer;


        left_boundary(root->left);

        leaves(root);

        right_boundary(root->right);
        return answer;
    }

    void left_boundary(TreeNode *root){
        if(root == nullptr)
            return;
        if(root->left == nullptr and root->right == nullptr)
            return;

        answer.push_back(root->val);
        if(root->left != nullptr)
            left_boundary(root->left);
        else
            left_boundary(root->right);
    }

    void right_boundary(TreeNode *root){
        if(root == nullptr)
            return;
        if(root->left == nullptr and root->right == nullptr)
            return;

        if(root->right != nullptr)
            right_boundary(root->right);
        else
            right_boundary(root->left);

        answer.push_back(root->val);
    }

    void leaves(TreeNode *root){
        if(root == nullptr)
            return;
        if(root->left == nullptr and root->right == nullptr){
            answer.push_back(root->val);
            return;
        }
        leaves(root->left);
        leaves(root->right);
    }

private:
    vector<int> answer;
};
*/
