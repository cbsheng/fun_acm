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
    //非递归解法
    //https://leetcode.com/discuss/19765/iterative-solution-in-java-simple-and-readable
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        
        TreeNode *cur = root;
        while (cur != NULL || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top();
            stk.pop();
            v.push_back(cur->val);
            cur = cur->right;
        }
        
        return v;
    }
};


//递归解法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalHelper(root, res);
        return res;
    }
    
    void inorderTraversalHelper(TreeNode* root, vector<int> &v) {
        if (root) {
            inorderTraversalHelper(root->left, v);
            v.push_back(root->val);
            inorderTraversalHelper(root->right, v);
        }
    }
};