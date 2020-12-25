// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return answer;
        TreeNode *curr_node;
        queue.push(root);
        int depth = 0;
        int size;

        while(!queue.empty()){
            size = queue.size();
            vector<int> curr_level(size);
            for(int i = 0; i < size; ++i){
                //pop and add to this levels vector
                curr_node = queue.front();
                queue.pop();
                curr_level[i] = curr_node->val;

                //now add shit to the queue
                if(curr_node->left != nullptr)
                    queue.push(curr_node->left);

                if(curr_node->right != nullptr)
                    queue.push(curr_node->right);
            }
            answer.push_back(curr_level);
            ++depth;
        }
        return answer;
    }
private:
    vector<vector<int>> answer;
    queue<TreeNode*> queue;
};



/*solution not using double nested loops
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return answer;
        TreeNode *curr_node;
        queue.push(root);
        int depth = 0;
        int level_size = 1;
        int next_level_size = 0;

        while(!queue.empty()){
            curr_node = queue.front();
            queue.pop();
            //if depth matches size we need to add a new vector to handle this next level
            if(answer.size() == depth)
                answer.push_back(vector<int>());

            //add the current node
            answer[depth].push_back(curr_node->val);

            --level_size;



            if(curr_node->left != nullptr){
                ++next_level_size;
                queue.push(curr_node->left);
            }
            if(curr_node->right != nullptr){
                ++next_level_size;
                queue.push(curr_node->right);
            }

            if(level_size == 0){
                ++depth;
                level_size = next_level_size;
                next_level_size = 0;
            }
        }
        return answer;
    }
private:
    vector<vector<int>> answer;
    queue<TreeNode*> queue;


*/
