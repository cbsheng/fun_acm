class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int beg = 0, end = A.size() - 1;
        int mid;
        while (beg < end) {
            mid = (beg + end) >> 1;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                beg = mid + 1;
            else
                end = mid;
        }
        
        if (beg == end) {
            if (A[beg] < target)
                return beg + 1;
            else
                return beg;
        }
        
        return 0;
    }
};
