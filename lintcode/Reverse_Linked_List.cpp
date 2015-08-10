/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
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

