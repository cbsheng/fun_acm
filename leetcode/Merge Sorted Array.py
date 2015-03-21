class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        res = []
        p_a, p_b = 0, 0
        while p_a != m or p_b != n:
            if p_a == m:
                res.append(B[p_b])
                p_b += 1
            elif p_b == n:
                res.append(A[p_a])
                p_a += 1
            elif A[p_a] < B[p_b]:
                res.append(A[p_a])
                p_a += 1
            elif B[p_b] < A[p_a]:
                res.append(B[p_b])
                p_b += 1
            else:
                res.append(A[p_a])
                p_a += 1
        for i, v in enumerate(res):
            A[i] = v