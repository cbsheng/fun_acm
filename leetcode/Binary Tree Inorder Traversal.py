# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
        order = []
        self.myintraversal(root, order)
        return order
    
    def myintraversal(self, root, order):
        if root:
            self.myintraversal(root.left, order)
            order.append(root.val)
            self.myintraversal(root.right, order)