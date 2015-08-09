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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (NULL == head)
            return NULL;
        
        ListNode *first = new ListNode(head->val);
        ListNode node(0);
        node.next = first;
        ListNode *dummy = &node;
        ListNode *q = head->next;
        
        while (q) {
            while (dummy->next) {
                if (dummy->next->val < q->val) {
                    dummy = dummy->next;
                }
                else
                    break;
            }
            ListNode *tmp = new ListNode(q->val);
            tmp->next = dummy->next;
            dummy->next = tmp;
            dummy = &node;
            q = q->next;
        }
        
        return dummy->next;
    }
};
