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
    int rob(TreeNode* root) {
        int a = tryr(root, true);
        int b = tryr(root, false);
        return max(a,b);
    }

    int tryr(TreeNode* root, bool try_root) {
        if (!root)
            return 0;
        int ret = 0;
        if (try_root) {
            ret = root->val;
            ret += tryr(root->left, false);
            ret += tryr(root->right, false);
        } else {
            int max_left = max(tryr(root->left, true), tryr(root->left, false));
            int max_right = max(tryr(root->right, true), tryr(root->right, false));
            ret += max_left + max_right;
        }
        return ret;
        
    }
};
