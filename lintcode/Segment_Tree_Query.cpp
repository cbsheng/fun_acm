/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (NULL == root || start > end)
            return 0;
        
        if (root->start == start && root->end == end)
            return root->max;
        int mid = (root->start + root->end) / 2;
        if (mid < start)
            return query(root->right, start, end);
        else if (end < mid)
            return query(root->left, start, end);
        else {
            int left = query(root->left, start, mid);
            int right = query(root->right, mid + 1, end);
            return left > right ? left : right;
        }
        
    }
};
