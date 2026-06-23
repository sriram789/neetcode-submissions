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
    unordered_map<int, int> nodePosition;
    int currentIndex = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int index = 0 ; index < inorder.size() ; index++)
            nodePosition[inorder[index]] = index;

        return buildTree(preorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootValue = preorder[currentIndex++];

        return new TreeNode(
            rootValue,
            buildTree(preorder, left, nodePosition[rootValue] - 1),
            buildTree(preorder, nodePosition[rootValue] + 1, right)
        );
    }
};
