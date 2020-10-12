/*
Link : https://leetcode.com/problems/add-two-numbers/
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

//Solution :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* curr = dummy;
        int carry = 0;
        while(p1 || p2){
            int x = (p1) ? p1->val : 0;
            int y = (p2) ? p2->val : 0;
            int sum = x + y + carry;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum/10;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }
        if(carry)
            curr->next = new ListNode(carry);
        return dummy->next;
    }
};
