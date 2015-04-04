# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param inorder, a list of integers
    # @param postorder, a list of integers
    # @return a tree node
    def buildTree(self, inorder, postorder):
        if postorder:
            root_val = postorder.pop()
            root = TreeNode(root_val)
            self.buildRightTree(root, inorder[inorder.index(root_val)+1:], postorder)
            self.buildLeftTree(root, inorder[:inorder.index(root_val)], postorder)
            return root
        
    def buildRightTree(self, root, inorder, ptorder):
        if inorder:    
            if len(inorder) == 1:
                root.right = TreeNode(inorder[0])
                ptorder.pop()
            else:
                mid = ptorder.pop()
                root.right = TreeNode(mid)
                self.buildRightTree(root.right, inorder[inorder.index(mid)+1:], ptorder)
                self.buildLeftTree(root.right, inorder[:inorder.index(mid)], ptorder)
    
    def buildLeftTree(self, root, inorder, ptorder):
        if inorder:    
            if len(inorder) == 1:
                root.left = TreeNode(inorder[0])
                ptorder.pop()
            else:
                mid = ptorder.pop()
                root.left = TreeNode(mid)
                self.buildRightTree(root.left, inorder[inorder.index(mid)+1:], ptorder)
                self.buildLeftTree(root.left, inorder[:inorder.index(mid)], ptorder)
        