class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return 0;
        
        int res = 0;
        int col = matrix[0].size() - 1, row = 0;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) res++;
            
            if (matrix[row][col] < target) row++;
            else if (matrix[row][col] >= target) col--;
        }
        return res;
    }
};

