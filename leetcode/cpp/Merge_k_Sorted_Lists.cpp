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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        ListNode dummy(0);
        ListNode *head = &dummy;
        multiset<int> sset;
        ListNode *p = NULL;
        for (int i = 0; i < lists.size(); ++i) {
            p = lists[i];
            while (p) {
                sset.insert(p->val);
                p = p->next;
            }
        }
        
        multiset<int>::iterator iter;
        for (iter = sset.begin(); iter != sset.end(); ++iter) {
            head->next = new ListNode(*iter);
            head = head->next;
        }
        
        return dummy.next;
    }
};