# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isValidBST(self, root):
        if root:
            self.inodr = []
            self.inorder(root)
            node = self.inodr[0]
            for i in self.inodr[1:]:
                if node >= i:
                    return False
                else:
                    node = i
        return True
    
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            self.inodr.append(root.val)
            self.inorder(root.right)