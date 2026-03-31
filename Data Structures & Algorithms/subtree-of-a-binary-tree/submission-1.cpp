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
    bool isSame(TreeNode* rootNode, TreeNode* subRoot)
    {
        if(!rootNode && !subRoot)
        {
            return true;
        }
        if(!subRoot || !rootNode)
        {
            return false;
        }
        // dont check for this condition in the above if else statement, thinking that this is anyway also returning false because trying to access the value if bychance that root was null will lead to a run time error
        if(rootNode->val != subRoot -> val)
        {
            return false;
        }

        return (isSame(rootNode->left, subRoot -> left) && isSame(rootNode->right, subRoot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
        {
            return true;
        }
        if(!root)
        {
            return false;
        }
        if (isSame(root, subRoot))
        {
            return true;
        }
        // if(isSame(root, subRoot))
        // {
        //     return true;
        // }
        // else if(isSame(root->left, subRoot))
        // {
        //     return true;
        // }
        // else(isSame(root->right, subRoot))
        // {
        //     return true;
        // }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
