class Solution:
    # @param {character[][]} grid
    # @return {integer}
	def numIslands(self, grid):
		row = len(grid)
		ans = 0
		if (ans == row): 
			return ans
		col = len(grid[0])
		for i in xrange(row):
			for j in xrange(col):
				if (grid[i][j] == '1'):
					self.dfs(grid, row, col, i, j)
					ans += 1
		return ans
		
	def dfs(self, grid, row, col, i, j):
		if (i < 0 or i >= row or j < 0 or j >= col or grid[i][j] != '1'):
			return
		grid[i][j] = '0'
		self.dfs(grid, row, col, i+1, j)
		self.dfs(grid, row, col, i-1, j)
		self.dfs(grid, row, col, i, j+1)
		self.dfs(grid, row, col, i, j-1)