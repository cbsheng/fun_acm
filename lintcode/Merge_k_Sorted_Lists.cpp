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
 //O(n^2)
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        
        ListNode dummy(0);
        ListNode *head = &dummy;
        ListNode **tmp;
        int min, first;
        do {
            tmp = NULL;
            first = 1;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != NULL) {
                    if (first) {
                        first = 0;
                        min = lists[i]->val;
                        tmp = &lists[i];
                    }
                    else {
                        if (lists[i]->val < min) {
                            min = lists[i]->val;
                            tmp = &lists[i];
                        }   
                    }
                }
            }
            
            if (tmp) {
                head->next = new ListNode((*tmp)->val);
                head = head->next;
                (*tmp) = (*tmp)->next;
            }
            else
                break;
        } while (1);
        
        return dummy.next;
    }
};


//multiset<int> Solution
//O(nlogn)
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        
        ListNode dummy(0);
        ListNode *head = &dummy;
        
        multiset<int> sset;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                ListNode *p = lists[i];
                while (p) {
                    sset.insert(p->val);
                    p = p->next;
                }
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