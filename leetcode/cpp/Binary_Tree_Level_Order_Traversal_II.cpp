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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> que;
        if (root)
            que.push(root);
        while (!que.empty()) {
            queue<TreeNode*> tmp;
            vector<int> v;
            while (!que.empty()) {
                root = que.front();
                que.pop();
                v.push_back(root->val);
                if (root->left)
                    tmp.push(root->left);
                if (root->right)
                    tmp.push(root->right);
            }
            que = tmp;
            res.push_back(v);
        }
        vector<vector<int> > ans;
        for (vector<vector<int> >::reverse_iterator iter = res.rbegin();
            iter != res.rend();
            ++iter)
            ans.push_back(*iter);
        return ans;
    }
};