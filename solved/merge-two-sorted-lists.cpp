// OJ: https://leetcode.com/problems/merge-two-sorted-lists/
// Author: https://github.com/brawnerquan
// Time: O(n + m)
// Space: O(n + m) (because of recursion)
//maybe I'll redo it so it's iterative sometime in the future.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode *head;
        // cout << l1->val << endl;
        // cout << l2->val << endl;
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        if(l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }       
};