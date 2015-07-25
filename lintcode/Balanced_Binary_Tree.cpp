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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
       if (height(root) == -1)
            return false;
        else
            return true;
    }
    
    int height(TreeNode * root) {
        if (NULL == root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
