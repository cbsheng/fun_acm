# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        if not root:
            return 0
        return self.myfun(root, 0)
    
    def myfun(self, root, sum):
        if not root.left and not root.right:
            return sum*10 + root.val
        else:
            left = right = 0
            if root.left:
                left = self.myfun(root.left, sum*10+root.val)
            if root.right:
                right = self.myfun(root.right, sum*10+root.val)
            return left + right