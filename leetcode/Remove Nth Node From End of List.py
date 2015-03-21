# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        myhead = ListNode(0)
        myhead.next = head
        now_head = myhead
        last_head = myhead
        p = head
        i = 0
        while p:
            i += 1
            if i == n:
                last_head = now_head
                now_head = p
                i = 0
            p = p.next
            
        if i == n:
            last_head.next = last_head.next.next
        elif last_head == myhead and i == 0:
            return head.next
        else:
            for j in range(i):
                last_head = last_head.next
            last_head.next = last_head.next.next
        return head
                    