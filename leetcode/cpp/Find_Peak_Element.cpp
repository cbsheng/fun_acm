//观察数组的性质，实际数组中的最大值肯定是顶峰。返回任意一个顶峰即可，所以二分搜，O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElementHelper(nums, 0, nums.size() - 1);
    }
    
    int findPeakElementHelper(vector<int> &nums, int beg, int end) {
        if (beg == end)
            return beg;
        else {
            int mid = (beg + end) >> 1;
            if (nums[mid] > nums[mid + 1])
                return findPeakElementHelper(nums, beg, mid);
            else
                return findPeakElementHelper(nums, mid + 1, end);
        }
    }
};

//非递归解法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0, end = nums.size() - 1;
        int mid;
        while (beg < end) {
            mid = (beg + end) >> 1;
            if (nums[mid] > nums[mid + 1])
                end = mid;
            else
                beg = mid + 1;
        }
        return beg;
    }
};

//遍历解决，机智
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};