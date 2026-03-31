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
    bool isChild(TreeNode* parent, TreeNode* child)
    {
        if(!parent)
        {
            return false;
        }
        if(parent == child)
        {
            return true;
        }
        return isChild(parent->left, child) || isChild(parent->right, child);
    }
public:
// how to declare this variable globally?
    TreeNode* LCA = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        {
            return LCA;
        }
        if(isChild(root, p) && isChild(root,q))
        {
            LCA = root;
        }
        // wont be the case that p and q are the children of both left and right, since each node is unique, so we can be assured that the variable LCA will be updated only when it is at the lowest possible node
        lowestCommonAncestor(root->left, p, q);
        lowestCommonAncestor(root->right, p, q);
        return LCA;
    }
};
