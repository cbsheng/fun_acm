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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> tmp;
        if (NULL == root)
            return tmp;
        
        vector<int> left = searchRange(root->left, k1, k2);
        vector<int> right = searchRange(root->right, k1, k2);
        
        if (k1 <= root->val and root->val <= k2) {
            tmp.insert(tmp.begin(), left.begin(), left.end());
            tmp.insert(tmp.end(), root->val);
            tmp.insert(tmp.end(), right.begin(), right.end());
        } else {
            tmp.insert(tmp.begin(), left.begin(), left.end());
            tmp.insert(tmp.end(), right.begin(), right.end());
        }
        return tmp;
    }
};
