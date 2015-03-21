# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        order = []
        self.myposttraversal(root, order)
        return order
        
    def myposttraversal(self, root, order):
        if root:
            self.myposttraversal(root.left, order)
            self.myposttraversal(root.right, order)
            order.append(root.val)