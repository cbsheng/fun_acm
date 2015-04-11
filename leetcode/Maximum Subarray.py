class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        res, c = -4294967296, 0
        for i in A:
            c = max(c + i, i)
            res = max(res, c)
        return res