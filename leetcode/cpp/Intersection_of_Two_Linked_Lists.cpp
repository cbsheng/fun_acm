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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        
        ListNode *ha = headA, *hb = headB;
        while (ha && hb && ha != hb) {
            ha = ha->next;
            hb = hb->next;
            
            if (ha == hb)
                return ha;
            
            if (!ha) ha = headB;
            if (!hb) hb = headA;
        }
        
        return ha;
    }
};