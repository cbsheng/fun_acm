# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        if not l1 and not l2:
            return None
        if not l1 and l2:
            return l2
        if not l2 and l1:
            return l1
        p1, p2 = l1, l2
        head = ListNode(0)
        p = head
        while p1 or p2:
            if not p1:
                p.next = ListNode(p2.val)
                p2 = p2.next
            elif not p2:
                p.next = ListNode(p1.val)
                p1 = p1.next
            elif p1.val < p2.val:
                p.next = ListNode(p1.val)
                p1 = p1.next
            elif p2.val < p1.val:
                p.next = ListNode(p2.val)
                p2 = p2.next
            else:
                p.next = ListNode(p1.val)
                p1 = p1.next
            p = p.next
        return head.next