# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        def fun(head, num):
            mid = num[len(num)/2]
            left = num[:num.index(mid)]
            right = num[num.index(mid)+1:]
            head.val = mid
            if left:
                head.left = TreeNode(0)
                fun(head.left, left)
            if right:
                head.right = TreeNode(0)
                fun(head.right, right)
            return head
        if not num:
            return None
        else:
            return fun(TreeNode(0), num)
        