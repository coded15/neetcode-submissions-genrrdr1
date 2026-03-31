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
// how to declare this variable globally? Ok so I am correct to declare the variable here and like this, the "null" error that I was getting was because in C++ their is nothing called "null". they have nullptr
    TreeNode* LCA = nullptr;
    // as I know, that since I am using recursion I am doing DFS and its not the most optimal solution out there, as I am not exploiting the information that it is a BST
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
