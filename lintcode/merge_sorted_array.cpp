class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int pos = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            A[pos--] = A[i] > B[j] ? A[i--] : B[j--];
        }

        while (j >= 0) {
            A[pos--] = B[j--];
        }
    }
};
