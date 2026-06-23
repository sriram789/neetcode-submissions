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
        if (!root) return {};

        queue<TreeNode*> levelOrderQueue;
        vector<vector<int>> result;

        levelOrderQueue.push(root);

        while (!levelOrderQueue.empty()) {
            int levelSize = levelOrderQueue.size(), index = 0;
            vector<int> currentLevelList;

            while (index++ < levelSize) {
                TreeNode* currentNode = levelOrderQueue.front(); levelOrderQueue.pop();
                currentLevelList.push_back(currentNode->val);
   
                if (currentNode->left) levelOrderQueue.push(currentNode->left);

                if (currentNode->right) levelOrderQueue.push(currentNode->right);
            }

            result.push_back(currentLevelList);
        }

        return result;
    }
};
