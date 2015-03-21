# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isSymmetric(self, root):
        if root == None:
            return True
        if not root.left and not root.right:
            return True
        l = [root.left, root.right]
        levelorder = []
        while l:
            temp = []
            temp_l = []
            for n in l:
                if n:
                    temp_l += [n.left, n.right]
                    temp.append(n.val)
                else:
                    temp.append(None)
                    temp_l.append(None)
            if len(temp) % 2 != 0 or temp != temp[::-1]:
                return False
            if set(temp_l) == {None}:
                return True
            else:
                l = temp_l
                    