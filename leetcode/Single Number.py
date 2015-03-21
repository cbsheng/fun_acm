class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        for i in A[1:]:
            A[0] ^= i
        return A[0]