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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (NULL == head)
            return NULL;
        else if (NULL == head->next)
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
        if (NULL == pre) return post;
        else if (NULL == post) return pre;
        
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
        if (pre) {
            head->next = pre;
        }
        if (post) {
            head->next = post;
        }
        
        return dummy.next;
    }
};



