// OJ: https://leetcode.com/problems/copy-list-with-random-pointer/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        vector<Node*> originalList;
        vector<Node*> newList;
        unordered_map<Node *, int> random_toIndex;
        Node *curr_node = head;
        int i = 0;
        //populate DS to allow constant time mapping from node pointer which node it is in the list
        while(curr_node != nullptr){
            originalList.push_back(curr_node);
            random_toIndex[curr_node] = i;
            ++i;
            curr_node = curr_node->next;
        }
        curr_node = head;
        //now copy
        Node *new_head = new Node(head->val);
        new_head->val = head->val;
        new_head->next = nullptr;
        newList.push_back(new_head);
        Node *curr_new_node;
        Node *previous = new_head;
        curr_node = curr_node->next;
        while(curr_node != nullptr){
            curr_new_node = new Node(curr_node->val);
            curr_new_node->val = curr_node->val;
            previous->next = curr_new_node;
            curr_new_node->next = nullptr;
            newList.push_back(curr_new_node);
            previous = curr_new_node;
            curr_node = curr_node->next;
        }
        curr_node = head;
        curr_new_node = new_head;
        while(curr_node != nullptr){
            if(curr_node->random != nullptr)
                curr_new_node->random = newList[random_toIndex[curr_node->random]];
            else
                curr_new_node->random = nullptr;
            previous = curr_new_node;
            curr_new_node = curr_new_node->next;
            curr_node = curr_node->next;
        }
        return new_head;
    }
};
