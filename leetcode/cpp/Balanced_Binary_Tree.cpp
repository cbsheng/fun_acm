/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
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