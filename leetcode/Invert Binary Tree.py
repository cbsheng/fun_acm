# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root:
            tmp = TreeNode(0)
            tmp = root.right
            root.right = root.left
            root.left = tmp
            self.invertTree(root.left)
            self.invertTree(root.right)
            return root
        else:
            return root