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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
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
