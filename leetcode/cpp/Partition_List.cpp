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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *big = &dummy, *small = &dummy;
        while (big && big->next && big->next->val < x)
            big = big->next;
        if (!big->next)
            return dummy.next;
        
        small = big;
        
        while (small && small->next) {
            if (small->next->val >= x) {
                small = small->next;
                continue;
            }
            ListNode *p = small->next;
            small->next = small->next->next;
            p->next = big->next;
            big->next = p;
            big = big->next;
        }
        return dummy.next;
    }
};