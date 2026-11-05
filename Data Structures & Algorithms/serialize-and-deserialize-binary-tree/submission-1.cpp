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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return ".,";
        }
        string result;
        result += to_string(root->val) + ',';
        result += serialize(root->left);
        result += serialize(root->right);
        return result;
    }

    TreeNode* deserializeHelper(stringstream& ss)
    {
        string token;
        getline(ss, token, ',');
        if(token == ".")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // string token;
        // stringstream ss(data);
        // getline(ss, token, ',');
        // if(token == ".")
        // {
        //     return nullptr;
        // }
        // TreeNode* root = new TreeNode(stoi(token));
        // root->left = deserialize(data);
        // root->right = deserialize(data);
        // return root;
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
