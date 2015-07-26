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
    //BST, not duplication
    //递归解法，这个解决也可以处理无重复结点的普通二叉树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root || root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (NULL != left && NULL != right)
            return root;
        else if (NULL == left && NULL != right)
            return right;
        else if (NULL == right && NULL != left)
            return left;
        return NULL;
    }
};





//非递归解法
//https://leetcode.com/discuss/44959/3-lines-with-o-1-space-1-liners-alternatives
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ((root->val - p->val) * (root->val - q->val) > 0)
            root = root->val > q->val ? root->left : root->right;
        return root;
    }
};