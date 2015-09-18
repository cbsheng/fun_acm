/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
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
        
        ListNode *p = NULL;
        for (int i = m; i < n; ++i) {
            if (!post) return NULL;
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

