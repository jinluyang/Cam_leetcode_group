/*
执行用时 :
24 ms
, 在所有 C++ 提交中击败了
99.45%
的用户
内存消耗 :
12.3 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        int maxlen = 0;
        for (auto item : root->children) {
            int dept = maxDepth(item);
            if (dept > maxlen)
                maxlen = dept;
            
        }
        return maxlen + 1;
    }
};
