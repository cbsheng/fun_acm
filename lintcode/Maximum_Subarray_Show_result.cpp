class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        if (nums.size() == 0) 
            return 0;
        
        int dp[nums.size()], mmax;
        mmax = dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] + nums[i] > nums[i])
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];
        
            if (mmax < dp[i])
                mmax = dp[i];
        }
        return mmax;
    }
};

