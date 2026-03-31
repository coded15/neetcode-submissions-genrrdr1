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
    vector<int> result;
    vector<int> rightSideViewGeneric(TreeNode* root)
    {
        if(!root)
        {
            return result;
        }
        result.push_back(root->val);
        if(root->right)
        rightSideViewGeneric(root->right);
        else
        rightSideViewGeneric(root->left);
        return result;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        result.push_back(root->val);
        vector<int> leftRightView;
        vector<int> rightRightView;
        if(root->left){
            leftRightView = rightSideViewGeneric(root->left);
        }
        if(root->right)
        {
            result.clear();
            result.push_back(root->val);
            rightRightView = rightSideViewGeneric(root->right);
        }
        cout << leftRightView.size();
        cout << rightRightView.size();

        if(rightRightView.size()<leftRightView.size())
        {
            for(int i = rightRightView.size(); i < leftRightView.size() && i > 0; i++)
            {
                cout << leftRightView[i] << " ";
                result.push_back(leftRightView[i]);
            }
        }
        cout << result.size();
        return result;
    }
};
