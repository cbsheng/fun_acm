/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end)
            return NULL;
        if (start == end)
            return new SegmentTreeNode(start, end);
        SegmentTreeNode *rt = new SegmentTreeNode(start, end);
        rt->left = build(start, (start + end) / 2);
        rt->right = build((start + end) / 2 + 1, end);
        return rt;
    }
};
