// OJ: https://leetcode.com/problems/binary-tree-right-side-view/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n) for the queue (up to n/2)
//solved both ways!
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if(root == nullptr)
            return answer;
        queue<TreeNode *> queue;
        queue.push(root);
        TreeNode *top;
        int size;
        while(!queue.empty()){
            size = queue.size();
            for(int i = 0; i < size; ++i){
                top = queue.front();
                queue.pop();
                if(i == size - 1)
                    answer.push_back(top->val);
                if(top->left != nullptr)
                    queue.push(top->left);
                if(top->right != nullptr)
                    queue.push(top->right);
            }
        }
        return answer;
    }
};

/* recursive solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if(root == nullptr)
            return answer;
        rightSideView(answer, root, 0);
        return answer;
    }
    void rightSideView(vector<int> &answer, TreeNode *root, int depth){
        //we visit the right most node of each level first, so add it to the answer bc that is what will be seen from the right!
        if(depth == answer.size())
            answer.push_back(root->val);

        if(root->right != nullptr)
            rightSideView(answer, root->right, depth + 1);
        if(root->left != nullptr)
            rightSideView(answer, root->left, depth + 1);
    }
};
*/
