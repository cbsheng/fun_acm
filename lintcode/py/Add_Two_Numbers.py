# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param l1: the first list
    # @param l2: the second list
    # @return: the sum list of l1 and l2 
    def addLists(self, l1, l2):
        if l1 is None or l2 is None:
            return l1 if l2 is None else l2
        
        a = self.transferToNumber(l1)
        b = self.transferToNumber(l2)
        res = a + b
        return self.transferToListNode(res)
        
    def transferToNumber(self, l):
        step = 1
        res = 0
        while l:
            res += step * l.val
            step = step * 10
            l = l.next
        return res
        
    def transferToListNode(self, n):
        head = ListNode(n % 10)
        p = head
        n = n / 10
        while n:
            p.next = ListNode(n % 10)
            n = n / 10
            p = p.next
        return head
