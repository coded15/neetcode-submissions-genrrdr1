/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return true;
        }
        if(!q || !p)
        {
            return false;
        }
        // dont check for this condition in the above if else statement, thinking that this is anyway also returning false because trying to access the value if bychance that root was null will lead to a run time error
        if(p->val != q -> val)
        {
            return false;
        }

        return (isSameTree(p->left, q -> left) && isSameTree(p->right, q->right));
    }
};
