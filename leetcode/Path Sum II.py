# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        self.res = []
        def fun(root, l, sum):
            if root:
                if not root.right and not root.left and sum == root.val:
                    return l + [root.val]
                if root.left:
                    left = fun(root.left, l+[root.val], sum-root.val)
                    if left:
                        self.res.append(left)
                if root.right:
                    right = fun(root.right, l+[root.val], sum-root.val)
                    if right:
                        self.res.append(right)
                
        res = fun(root, [], sum)
        if res:
            self.res.append(res)
        return self.res