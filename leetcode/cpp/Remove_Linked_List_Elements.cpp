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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode *p;
        while (head && head->next) {
            if (head->next->val == val) {
                p = head->next;
                head->next = head->next->next;
                delete p;
            }
            else
                head = head->next;
        }
        
        return dummy.next;
    }
};