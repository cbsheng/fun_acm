class Solution:
    # @param {character[][]} grid
    # @return {integer}
	def numIslands(self, grid):
		row = len(grid)
		if (0 == row): 
			return 0
		col = len(grid[0])
		self.visited = [] #结点是否已访问过
		for i in xrange(row):
			self.visited.append([0] * col)
		ans = 0
		for i in xrange(row):
			for j in xrange(col):
				if (not self.visited[i][j] and grid[i][j] == '1'):
					self.dfs(grid, row, col, i, j)
					ans += 1
		return ans
		
	def dfs(self, grid, row, col, i, j):
		self.visited[i][j] = 1
		if (j != 0):
			# left
			if (not self.visited[i][j-1] and grid[i][j-1] == '1'): self.dfs(grid, row, col, i, j-1)
			else: self.visited[i][j-1] = 1
		if (i != 0):
			# up
			if (not self.visited[i-1][j] and grid[i-1][j] == '1'): self.dfs(grid, row, col, i-1, j)
			else: self.visited[i-1][j] = 1
		if (j < col-1):
			# right
			if (not self.visited[i][j+1] and grid[i][j+1] == '1'): self.dfs(grid, row, col, i, j+1)
			else: self.visited[i][j+1] = 1
		if (i < row-1):
			# down
			if (not self.visited[i+1][j] and grid[i+1][j] == '1'): self.dfs(grid, row, col, i+1, j)
			else: self.visited[i+1][j] = 1