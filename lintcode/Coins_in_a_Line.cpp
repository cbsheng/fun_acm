class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        int dp[n];
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i < n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n - 1] % 2 == 0 ? false : true;
    }
    
};
