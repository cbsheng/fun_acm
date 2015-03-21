# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if not head:
            return None
        if not head.next:
            return head
        else:
            first = ListNode(0)
            first.next = head
            cur = first
            while cur.next:
                pre = cur.next
                nxt = cur.next.next
                if not nxt:
                    break
                cur.next = nxt
                pre.next = nxt.next
                nxt.next = pre
                cur = pre
            return first.next
                