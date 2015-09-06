class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        int number = nums[0], times = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (0 == times) {
                number = nums[i];
                times = 1;
            }
            if (nums[i] != number)
                times--;
            else if (nums[i] == number)
                times++;
        }
        if (times <= 0)
            return 0;
        else
            return number;
    }
};

