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
    bool isValidBST(TreeNode* root) {
        vector<int> assist;
        return isValidBSTHelper(root, assist);
    }
    
    bool isValidBSTHelper(TreeNode *root, vector<int> &a) {
        if (root) {
            bool left = isValidBSTHelper(root->left, a);
            if (a.size() > 0) {
                if (a[a.size() - 1] >= root->val)
                    return false;
                else
                    a.push_back(root->val);
            } else {
                a.push_back(root->val);
            }
            bool right = isValidBSTHelper(root->right, a);
            return left && right;
        }
        return true;
    }
};