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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    stack<TreeNode*> stk;
    TreeNode *cur;
    
    Solution(TreeNode *root) {
        while (!stk.empty())
            stk.pop();
        cur = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return NULL != cur || !stk.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        TreeNode *p = stk.top();
        stk.pop();
        cur = p->right;
        return p;
    }
};
