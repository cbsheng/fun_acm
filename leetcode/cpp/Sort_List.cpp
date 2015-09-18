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
    ListNode* sortList(ListNode* head) {
        if (NULL == head)
            return NULL;
        if (NULL == head->next)
            return head;
        ListNode *mid = findMid(head);
        ListNode *pre = sortList(head);
        ListNode *post = sortList(mid);
        return mergeTwoList(pre, post);
    }
    
    ListNode* findMid(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        while (fast) {
            if (NULL == fast->next)
                break;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p = slow->next;
        slow->next = NULL;
        return p;
    }
    
    ListNode* mergeTwoList(ListNode *pre, ListNode *post) {
        ListNode dummy(0);
        ListNode *head = &dummy;
        
        while (pre && post) {
            if (pre->val < post->val) {
                head->next = pre;
                pre = pre->next;
            }
            else {
                head->next = post;
                post = post->next;
            }
            head = head->next;
        }
        
        if (pre) head->next = pre;
        else if (post) head->next = post;
        
        return dummy.next;
    }
};