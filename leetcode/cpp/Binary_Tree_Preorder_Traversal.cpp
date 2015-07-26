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
    vector<int> preorderTraversal(TreeNode* root) {
        //非递归解法
        vector<int> res;
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            if (root->right)
                stk.push(root->right);
            if (root->left)
                stk.push(root->left);
        }
        return res;
    }
};