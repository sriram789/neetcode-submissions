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
        if (!root)
            return "NULL";

        return to_string(root->val) + "," +
            serialize(root->left) + "," +
            serialize(root->right);
    }

     TreeNode* build(vector<string>& nodes, int &index) {
        if (nodes[index] == "NULL") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index++]));

        root->left = build(nodes, index);
        root->right = build(nodes, index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;

        stringstream ss(data);

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int index = 0;
        return build(nodes, index);
    }
};
