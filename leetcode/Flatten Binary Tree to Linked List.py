# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        stack = []
        if root:
            if root.right:
                stack.append(root.right)
            if root.left:
                stack.append(root.left)
            stack.append(root)
            while len(stack) >= 2:
                pre = stack.pop()
                nxt = stack.pop()
                pre.right = nxt
                pre.left = None
                if nxt.right:
                    stack.append(nxt.right)
                if nxt.left:
                    stack.append(nxt.left)
                stack.append(nxt)