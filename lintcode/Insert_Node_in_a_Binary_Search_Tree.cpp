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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (NULL == root) {
            return node;
        }
        TreeNode *head = root;
        while (root) {
            if (root->val < node->val) {
                if (NULL != root->right) {
                    root = root->right;
                } else {
                    root->right = node;
                    return head;
                }
            }
            else {
                if (NULL != root->left) {
                    root = root->left;
                } else {
                    root->left = node;
                    return head;
                }
            }
        }
    }
};
