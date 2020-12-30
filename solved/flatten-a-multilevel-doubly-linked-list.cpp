// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: https://github.com/brawnerquan
// Time: O(n) because you have to traverse the linked list
// Space: O(1)
//solved recurisvely and iteratively
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)
            return head;

        stack<Node *> stack;
        stack.push(head);
        Node *top;
        Node *previous = nullptr;
        while(!stack.empty()){
            top = stack.top();
            stack.pop();
            if(previous != nullptr)
                previous->next = top;
            top->prev = previous;

            if(top->next != nullptr)
                stack.push(top->next);

            if(top->child != nullptr){
                stack.push(top->child);
                top->child = nullptr;
            }

            previous = top;
        }
        return head;
    }

};

/*

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)
            return head;
        flatten(head, nullptr);
        return head;
    }

    Node *flatten(Node *head, Node *prev){
        if(head == nullptr)
            return prev;
        if(prev != nullptr)
            prev->next = head;

        head->prev = prev;

        Node *next = head->next;
        Node *tail = flatten(head->child, head);
        head->child = nullptr;

        return flatten(next, tail);
    }

};

*/
