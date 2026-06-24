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
    int maximum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maximum;
    }

    int maxGain(TreeNode* root) {
        if (!root)
            return 0;

        int leftSum = max(0, maxGain(root->left));
        int rightSum = max(0, maxGain(root->right));

        // Update the overall maximum path
        maximum = max(maximum, root->val + leftSum + rightSum);

        // Return the best path that can be extended upward
        return root->val + max(leftSum, rightSum);
    }
};
