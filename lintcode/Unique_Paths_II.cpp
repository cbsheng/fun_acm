class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int dp[row][col];
        dp[0][0] = 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obstacleGrid[i][j]){
                    dp[i][j] = 0;
                    continue;
                }
                if ((0 == i && 0 == j))
                    continue;
                if (i - 1 < 0)
                    dp[i][j] = dp[i][j - 1];
                else if (j - 1 < 0)
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        
        return dp[row - 1][col - 1];
    }
};



//Solution 2
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        int dp[row + 1][col + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[row][col];
    }
};