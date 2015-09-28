/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (NULL == root || start > end || root->end < start || end < root->start)
            return 0;
        
        if (root->end < end)
            end = root->end;
        if (start < root->start)
            start = root->start;
            
        if (root->start == start && root->end == end)
            return root->count;
        int mid = (root->start + root->end) / 2;
        if (mid < start)
            return query(root->right, start, end) ;
        else if (end < mid)
            return query(root->left, start, end);
        else
            return query(root->left, start, mid) + query(root->right, mid + 1, end);
            
    }
};
