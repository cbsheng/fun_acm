class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (0 == i && 0 == j)
                    continue;
                if (i - 1 < 0)
                    grid[i][j] += grid[i][j - 1];
                else if (j - 1 < 0)
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[row - 1][col - 1];
    }
};