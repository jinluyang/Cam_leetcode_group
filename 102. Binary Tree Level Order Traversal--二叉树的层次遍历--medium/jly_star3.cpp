/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 执行用时 :
8 ms
, 在所有 C++ 提交中击败了
58.76%
的用户
内存消耗 :
14.3 MB
, 在所有 C++ 提交中击败了
25.30%
的用户
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> cur;
        if (root == nullptr)
            return res;
        cur.push(root);
        while(!cur.empty()) {
            queue<TreeNode*> child;
            vector<int> values;
            while(!cur.empty()) {
                values.push_back((cur.front())->val);
                TreeNode* current = cur.front();
                if (current->left)
                    child.push(current->left);
                if (current->right)
                    child.push(current->right);
                cur.pop();
                
            }
            res.push_back(values);
            //values = new vector<int>();
            cur = child;
            //child = new queue<TreeNode*>;

        }
        return res;
    }
};
