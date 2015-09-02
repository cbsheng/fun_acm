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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (NULL == head || 0 == n) return NULL;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        int k = n;
        while (k > 0 && fast->next) {
            fast = fast->next;
            k--;
        }
        if (k != 0) return NULL;
        
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummy.next;
    }
};



