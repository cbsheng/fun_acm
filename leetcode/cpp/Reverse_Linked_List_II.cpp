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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode *pre, *post;
        for (int i = 0; i < m - 1; ++i) {
            head = head->next;
            if (!head) return NULL;
        }
        
        pre = head->next;
        if (!pre->next) return NULL;
        else post = pre->next;
        
        ListNode *p;
        for (int i = m; i < n; ++i) {
            if (!post)  return NULL;
            p = post->next;
            post->next = pre;
            pre = post;
            post = p;
        }
        head->next->next = post;
        head->next = pre;
        return dummy.next;
    }
};