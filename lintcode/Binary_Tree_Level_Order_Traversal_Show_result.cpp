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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        queue<TreeNode*> que;
        if (root)
            que.puash(root);
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
        return res;
    }
};

