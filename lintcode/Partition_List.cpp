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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        if (NULL == head)
            return NULL;
        
        ListNode leftdummy(0);
        ListNode rightdummy(0);
        ListNode *lefttail = &leftdummy;
        ListNode *righttail = &rightdummy;
        
        while (head) {
            if (head->val < x) {
                lefttail->next = head;
                lefttail = head;
            } else {
                righttail->next = head;
                righttail = head;
            }
            head = head->next;
        }
        
        lefttail->next = rightdummy.next;
        righttail->next = NULL;
        return leftdummy.next;
    }
};



