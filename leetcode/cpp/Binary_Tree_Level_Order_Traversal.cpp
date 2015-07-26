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
    //非递归版本，但是用了两个 queue，不好。
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return res;
    }
};




//非递归解法， 用了一个 queue，The Best Solution.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if (!root) return v;
        
        queue<TreeNode*> que;
        que.push(root);
        
        TreeNode *p = NULL;
        int size;
        while (!que.empty()) {
            size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                p = que.front();
                que.pop();
                tmp.push_back(p->val);
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            v.push_back(tmp);
        }
        
        return v;
    }
};