# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        if not root:
            return None
        nodes = [root]
        while nodes:
            p = 0
            while p + 1 != len(nodes):
                nodes[p].next = nodes[p+1]
                p += 1
            nodes[p].next = None
            temp = []
            for i in nodes:
                if i.left:
                    temp.append(i.left)
                if i.right:
                    temp.append(i.right)
            nodes = temp