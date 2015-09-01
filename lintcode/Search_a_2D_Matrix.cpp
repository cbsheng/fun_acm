class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int col = matrix[0].size() - 1, row = 0;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else if (matrix[row][col] > target) col--;
        }
        return false;
    }
};