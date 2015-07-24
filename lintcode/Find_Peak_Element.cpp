class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        //lintcode 上的测试数据视乎不够好，建议到 leetcode 刷这题。https://leetcode.com/problems/find-peak-element/
        return findPeakHelper(A, 0, A.size() - 1);
    }
    
    int findPeakHelper(vector<int> &A, int beg, int end) {
        if (beg == end) 
            return beg;
        else {
            int mid = (beg + end) >> 1;
            if (A[mid] > A[mid + 1])
                return findPeakHelper(A, beg, mid);
            else
                return findPeakHelper(A, mid + 1, end);
        }
    }
};