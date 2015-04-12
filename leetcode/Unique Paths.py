class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        self.table = [[]]*m
        for i in range(m):
            self.table[i] = [None] * n
            
        def fun(mm, nn, m, n):
            if mm == m and nn == n:
                return 1
            if self.table[mm-1][nn-1]:
                return self.table[mm-1][nn-1]
            a, b = 0, 0
            if mm + 1 <= m:
                #down
                a = fun(mm+1, nn, m, n)
            if nn + 1 <= n:
                #right
                b = fun(mm, nn+1, m, n)
            self.table[mm-1][nn-1] = a+b
            return a + b
        if m and n:
            return fun(1, 1, m, n)
        else:
            return 0