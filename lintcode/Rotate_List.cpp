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
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        int size = getSize(head);
        if (0 == k || 0 == size || size == k)
            return head;
        int interval = k % size;
            
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        while (interval--) {
            fast = fast->next;
        }
        while (NULL != fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = dummy.next;
        dummy.next = slow->next;
        slow->next = NULL;
        return dummy.next;
    }
    
    int getSize(ListNode *head) {
        int size = 0;
        while (head) {
            head = head->next;
            size++;
        }
        return size;
    }
};
