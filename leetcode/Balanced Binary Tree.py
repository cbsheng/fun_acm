# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isBalanced(self, root):
        
        if root == None:
            return True
        left = self.depth(root.left)
        right = self.depth(root.right)
        return abs(left-right) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)
    
    def depth(self, root):
        if root == None:
            return 0
        return max(self.depth(root.left), self.depth(root.right)) + 1