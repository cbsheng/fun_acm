# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = []
        self.inorder_traversal(root)

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return len(self.stack)

    # @return an integer, the next smallest number
    def next(self):
        return self.stack.pop()
        
    def inorder_traversal(self, root):
        if root:
            self.inorder_traversal(root.right)
            self.stack.append(root.val)
            self.inorder_traversal(root.left)
        

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())