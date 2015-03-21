# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        if root == None:
            return []
        l = [root]
        levelorder = []
        while l:
            levelorder.append([n.val for n in l])
            ll = l[:]
            l = []
            for i in ll:
                if i.left:
                    l.append(i.left)
                if i.right:
                    l.append(i.right)
        return levelorder