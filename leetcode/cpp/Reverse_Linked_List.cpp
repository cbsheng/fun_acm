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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head)
            return NULL;
        
        ListNode dummy(0);
        ListNode *h = &dummy;
        ListNode *p = head;
        while (p) {
            ListNode *tmp = new ListNode(p->val);
            tmp->next = h->next;
            h->next = tmp;
            p = p->next;
        }
        return dummy.next;
    }
};