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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        
        while (p) {
            if (NULL != p->next && p->next->val == p->val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }
        
        return head;
    }
};
