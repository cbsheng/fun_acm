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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (NULL == root)
            return res;
        vector<TreeNode*> queue;
        queue.push_back(root);
        
        zigzagLevelOrderHelper(queue, res, 1);
        return res;
    }
    
    void zigzagLevelOrderHelper(vector<TreeNode*> &q, vector<vector<int> > &res, int flag) {
        if (q.size()) {
            vector<TreeNode*> tmp_l;
            for (int i = 0; i < q.size(); ++i) {
                if (q[i]->left)
                    tmp_l.push_back(q[i]->left);
                if (q[i]->right)
                    tmp_l.push_back(q[i]->right);
            }
            vector<int> v;
            if (flag) {
                for (vector<TreeNode*>::iterator iter = q.begin(); iter != q.end(); ++iter) {
                    v.push_back((*iter)->val);
                }
            } else {
                for (vector<TreeNode*>::reverse_iterator iter = q.rbegin(); iter != q.rend(); ++iter) {
                    v.push_back((*iter)->val);
                }
            }
            res.push_back(v);
            q = tmp_l;
            zigzagLevelOrderHelper(q, res, !flag);
        }
    }
};
