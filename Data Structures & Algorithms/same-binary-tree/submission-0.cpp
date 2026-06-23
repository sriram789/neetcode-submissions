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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pList = {}; getTreeList(p, pList);
        vector<TreeNode*> qList = {}; getTreeList(q, qList);

        if (pList.size() != qList.size()) return false;

        for (int index = 0 ; index < pList.size() ; index++) {
            if (pList[index] == nullptr && qList[index] == nullptr)
                continue;

            if (pList[index] == nullptr || qList[index] == nullptr)
                return false;

            if (pList[index]->val != qList[index]->val)
                return false;
        }

        return true;
    }

    void getTreeList(TreeNode *p, vector<TreeNode*> &initialList) {
        if (!p) { initialList.push_back(nullptr); return; }

        initialList.push_back(p);
        getTreeList(p->left, initialList);
        getTreeList(p->right, initialList);
    }
};
