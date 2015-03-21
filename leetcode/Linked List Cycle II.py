# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        if not head:
            return None
        else:
            d = {}
            p = head
            while p:
                if d.has_key(p):
                    return p
                else:
                    d[p] = 1
                p = p.next
            return None