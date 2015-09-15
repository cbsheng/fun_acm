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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (NULL == head)
            return false;
        
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && slow) {
            if (NULL == fast->next) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};



