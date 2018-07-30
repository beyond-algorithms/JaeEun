/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int prev = -1, cur = 987654321;
    int minDiffInBST(TreeNode* root) {
        if (!root) {
            return 0;
        }
        minDiffInBST(root->left);

        if (prev > 0) cur = min(root->val - prev, cur);
        prev = root->val;

        minDiffInBST(root->right);
        return cur;
    }
};
