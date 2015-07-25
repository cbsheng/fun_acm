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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversalHelper(root, res);
        return res;
    }
    
    void preorderTraversalHelper(TreeNode *root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            preorderTraversalHelper(root->left, res);
            preorderTraversalHelper(root->right, res);
        }
    }
};


//非递归写法
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