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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1 && NULL == l2)
            return NULL;
            
        ListNode first(0);
        ListNode *dummy = &first;
        
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            if (p1->val > p2->val) {
                dummy->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            else {
                dummy->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            dummy = dummy->next;
        }
        
        if (NULL == p1) {
            copyList(dummy, p2);
        }
        else {
            copyList(dummy, p1);
        }
        return first.next;
    }
    
    void copyList(ListNode *des, ListNode *src) {
        while (src) {
            des->next = new ListNode(src->val);
            des = des->next;
            src = src->next;
        }
    }
};
