class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if not A:
            return None
        old = A[0]
        nxt = 1
        for elem in A[1:]:
            if elem != old:
                A[nxt] = elem
                nxt += 1
                old = elem
        return nxt