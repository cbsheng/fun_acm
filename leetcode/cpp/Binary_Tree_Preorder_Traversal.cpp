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
       vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        //TreeNode tmp;
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            if (NULL == root)
                continue;
            res.push_back(root->val);
            stk.push(root->right);
            stk.push(root->left);
        }
        return res;
    }
};