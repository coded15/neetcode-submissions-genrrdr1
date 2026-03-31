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
int maxDiameter = 0;

    int height(TreeNode* root){
        if(!root) return 0;
        int x = height(root->left);
        int y = height(root->right);
        return 1 + max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int x = height(root -> left);
        int y = height(root -> right);
        maxDiameter = max(maxDiameter, x + y);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDiameter; 
    }
};
