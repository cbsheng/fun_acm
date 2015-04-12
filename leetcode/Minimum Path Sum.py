class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        m, n = len(grid)-1, len(grid[0])-1
        table = [[]] * (m+1)
        for i in range(m+1):
            table[i] = [None] * (n+1)
            
        def fun(mm, nn):
            if mm == m and nn == n:
                return grid[mm][nn]
            if table[mm][nn]:
                return table[mm][nn]
            a, b = 4294967296, 4294967296
            #down
            if mm + 1 <= m:
                a = fun(mm+1, nn)
            #right
            if nn + 1 <= n:
                b = fun(mm, nn+1)
            table[mm][nn] = min(a, b) + grid[mm][nn]
            return table[mm][nn]
        if grid:
            return fun(0,0)
        else:
            return 0