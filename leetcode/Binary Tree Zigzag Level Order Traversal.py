# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def zigzagLevelOrder(self, root):
        if root:
            queue = [root]
            zigzagOrder = []
            level = 0
            while queue:
                temp_queue = []
                for i in queue:
                    if i.left:
                        temp_queue.append(i.left)
                    if i.right:
                        temp_queue.append(i.right)
                if level % 2 != 0:
                    zigzagOrder.append([n.val for n in queue][::-1])
                else:
                    zigzagOrder.append([n.val for n in queue])
                queue = temp_queue
                level += 1
            return zigzagOrder
        else:
            return []