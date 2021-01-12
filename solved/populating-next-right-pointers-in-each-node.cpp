// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(1) (still recursion stack used lol)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//constant space solution
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        connectNodes(root);
        return root;
    }

    void connectNodes(Node *root){
        if(root == nullptr)
            return;
        if(root->next != nullptr and root->right != nullptr)
            root->right->next = root->next->left;
        if(root->left != nullptr)
            root->left->next = root->right;

        connectNodes(root->left);
        connectNodes(root->right);
    }
};


/* iterative solution not using constant space
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        queue<Node*> queue;
        queue.push(root);
        Node *prev, *front;
        int size;
        while(!queue.empty()){
            size = queue.size();
            for(int i = 0; i < size - 1; ++i){
                prev = queue.front();
                if(prev->left != nullptr)
                    queue.push(prev->left);
                if(prev->right != nullptr)
                    queue.push(prev->right);
                queue.pop();
                prev->next = queue.front();
            }
            //dont mess with the last one in the level, just add it's children
            front = queue.front();
            if(front->left != nullptr)
                queue.push(front->left);
            if(front->right != nullptr)
                queue.push(front->right);
            queue.pop();
        }
        return root;
    }
};
*/
