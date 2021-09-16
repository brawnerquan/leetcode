// OJ: https://leetcode.com/problems/swap-nodes-in-pairs/
// Author: https://github.com/brawnerquan
// Time: O(n)
// Space: O(n) for the recursion stack
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //empty case and singleton case
        if(head == nullptr or head->next == nullptr)
            return head;
        //swap the first two,
        ListNode *new_head = head->next;
        ListNode *remaining = head->next->next;
        new_head->next = head;
        head->next = swapPairs(remaining);
        //recursive leap of faith to swap the remaining list
        return new_head;
    }
};