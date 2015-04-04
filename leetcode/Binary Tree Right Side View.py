# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def rightSideView(self, root):
        self.res = []
        def fun(root, level):
            if root:
                if len(self.res) < level:
                    self.res.append(root.val)
                fun(root.right, level+1)
                fun(root.left, level+1)
        fun(root, 1)
        return self.res