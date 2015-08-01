class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int len = A.size();
        if (!len)
            return 0;
            
        int increase_dp[len];
        int decrease_dp[len];
        increase_dp[0] = 1;
        decrease_dp[0] = 1;
        
        int mmax = 1;
        for (int i = 1; i < len; ++i) {
            increase_dp[i] = (A[i] >= A[i - 1]) ? increase_dp[i - 1] + 1 : 1;
            decrease_dp[i] = (A[i] <= A[i - 1]) ? decrease_dp[i - 1] + 1 : 1;
                
            if (increase_dp[i] > mmax)
                mmax = increase_dp[i];
            if (decrease_dp[i] > mmax)
                mmax = decrease_dp[i];
        }
        
        return mmax;
    }
};
