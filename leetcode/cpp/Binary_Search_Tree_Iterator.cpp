/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode *cur;
    
    BSTIterator(TreeNode *root) {
        while (!stk.empty())
            stk.pop();
        cur = root;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return NULL != cur || !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        
        TreeNode *p = stk.top();
        stk.pop();
        cur = p->right;
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */