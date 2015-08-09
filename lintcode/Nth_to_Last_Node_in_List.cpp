/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        if (NULL == head)
            return NULL;
        int total = 0;
        ListNode *p = head;
        while (p) {
            total++;
            p = p->next;
        }
        total -= n;
        while (total > 0) {
            head = head->next;
            total--;
        }
        return head;
    }
};



