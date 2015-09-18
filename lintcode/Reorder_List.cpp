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
    ListNode *cur;
    void reorderList(ListNode* head) {
        int size = getSize(head);
        if (size <= 2)
            return;
        
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
        if (size % 2 == 0) {
            p = slow->next->next;
            slow = slow->next;
        }
        slow->next = NULL;
        cur = head;
        reorderListHelper(p);
    }
    
    int getSize(ListNode *head) {
        int num = 0;
        while (head) {
            num++;
            head = head->next;
        }
        return num;
    }
    
    void reorderListHelper(ListNode *post) {
        if (NULL == post)
            return;
        reorderListHelper(post->next);
        post->next = cur->next;
        cur->next = post;
        cur = post->next;
    }
};