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
    ListNode* insertionSortList(ListNode* head) {
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