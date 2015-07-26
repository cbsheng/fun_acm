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
    //非递归解法，利用了从右子树开始的前序遍历是后序遍历
    //代码很简洁，代码篇幅不长，涉及变量不多，所以单用 v 这样一个字母的命名会更好看
    //https://leetcode.com/discuss/21995/a-very-concise-solution
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (!root) return v;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        TreeNode *p = NULL;
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            v.insert(v.begin(), p->val);
            if (p->left) stk.push(p->left);
            if (p->right) stk.push(p->right);
        }
        
        return v;
    }
};



//递归解法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversalHelper(root, res);
        return res;
    }
    
    void postorderTraversalHelper(TreeNode* root, vector<int> &v) {
        if (root) {
            postorderTraversalHelper(root->left, v);
            postorderTraversalHelper(root->right, v);
            v.push_back(root->val);
        }
    }
};