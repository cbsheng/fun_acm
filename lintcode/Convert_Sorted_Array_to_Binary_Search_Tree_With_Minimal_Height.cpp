/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        if (A.size() == 0)
            return NULL;
        
        return sortedArrayToBSTHelper(A, 0, A.size() - 1);
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int> &A, int beg, int end) {
        if (beg == end)
            return new TreeNode(A[beg]);
        
        int mid = beg + ((end - beg) >> 1);
        TreeNode *rt = new TreeNode(A[mid]);
        if (beg < mid)
            rt->left = sortedArrayToBSTHelper(A, beg, mid - 1);
        if (mid < end)
            rt->right = sortedArrayToBSTHelper(A, mid + 1, end);
        return rt;
    }
};



