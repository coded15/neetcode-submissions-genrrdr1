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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // I stumbled on the fact that how will I know that in the queue that I am maintaining, before I pop the front element how would I know in which vector to push that value. I mean like I cant just pop an element when I am done pushing its children before I have no idea on where I will push them.
        queue<TreeNode* > q;
        vector<vector<int>> result;
        // vector<int> level;
        // level.push(q->val);
        if(!root)
        {
            return {};
        }
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int level = q.size();
            for(int i = level; i > 0; i--)
            {
                // dont directly push as because left or right can be null and when in the next iteration I try to access its value, I will get a segmentation error
                // q.push(q.front()->left);
                // q.push(q.front()->right);
                // temp.push_back(q.front()->val);
                TreeNode* node = q.front();
                // pop it outside the below if condition
                q.pop();
                // Now when I am checking that the front node is null or not, it will not prevent the null left and right to get inserted inside queue, but while we are iterating on the queue the below check will not let us access the left and right of null node
                if(node)
                {
                    q.push(node->left);
                    q.push(node->right);
                    temp.push_back(node->val);   
                }
            }
            // level = q.size();
            if(!temp.empty())
            result.push_back(temp);
        }
        return result;
    }
};
