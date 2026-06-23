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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedList;
        preorderList(root, sortedList);

        return sortedList[k-1];
    }

    void preorderList(TreeNode* root, vector<int> &sortedList) {
        if (!root) return;

        preorderList(root->left, sortedList);
        sortedList.push_back(root->val);
        preorderList(root->right, sortedList);
    }
};
