// OJ: https://leetcode.com/problems/add-two-numbers/
// Author: https://github.com/brawnerquan
// Time: O()
// Space: O()
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return returnSum(l1, l2);
    }
    ListNode* returnSum(ListNode* l1, ListNode* l2){
        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int sum, carryover, l1_val, l2_val;
        carryover = 0;
        while(l1_curr != nullptr or l2_curr != nullptr){
            if(l1_curr != nullptr)//if the current number dosen't exist, dont fuc kup
                l1_val = l1_curr->val;
            else
                l1_val = 0;
            if(l2_curr != nullptr)
                l2_val = l2_curr->val;
            else
                l2_val = 0;
            sum = l1_val + l2_val + carryover;
            carryover = sum/10;
            sum = sum % 10;
            if(head == nullptr){//add new sum to the list
                head = new ListNode(sum);
                tail = head;    
            }else{
                tail->next = new ListNode(sum);
                tail = tail->next;//update tail
            }
            //increment the pointers for the two numbers being added, if one is already at the end, dont increment
            if(l1_curr != nullptr)
                l1_curr = l1_curr->next;
            if(l2_curr != nullptr)
                l2_curr = l2_curr->next;
        }
        if(carryover == 1)
            tail->next = new ListNode(1);
        return head;
    }
};