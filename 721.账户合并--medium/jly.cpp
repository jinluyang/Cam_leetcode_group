/*
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该帐户的邮箱地址。

现在，我们想合并这些帐户。如果两个帐户都有一些共同的邮件地址，则两个帐户必定属于同一个人。请注意，即使两个帐户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的帐户，但其所有帐户都具有相同的名称。

合并帐户后，按以下格式返回帐户：每个帐户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。accounts 本身可以以任意顺序返回。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/accounts-merge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


考察并查集，这题不简单，最后发现还要排序，不仅要排序还要去重，懒得再写去重了。
*/
class Solution {
public:
    unordered_map<string, string> parent;
    string find(string q) {
        if (parent[q] == q)
            return q;
        return find(parent[q]);
    }
    void unio(string a, string b) {
        string roota = find(a);
        string rootb = find(b);
        if (roota == rootb)
            return;
        parent[rootb] = roota;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        vector<vector<string>> res;
        //res.push_back(accounts[0]);

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (parent.count(accounts[i][j]) == 0) {
                    parent[accounts[i][j]] = accounts[i][1];
                } else {
                    unio(accounts[i][1], accounts[i][j]);

                }

            }
        }
        unordered_map<string, int> m;
        //m[find(accounts[0][1])] = 0;
        int idx= 0;

        for (int i = 0; i < accounts.size(); i++) {
            if (m.count(find(accounts[i][1])) == 0) {
                res.push_back(accounts[i]);
                m[find(accounts[i][1])] = idx;
                idx++;
            } else {
                int ind = m[find(accounts[i][1])];
                for (int j = 1; j < accounts[i].size(); j++) {
                    string em = accounts[i][j];
                    bool found = false;
                    for (string email : res[ind]) {
                        if (email == em) {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        res[ind].push_back(em);
                }

            }
 
            
        }
        for (int i = 0; i < res.size() ; i++) {
            sort((res[i].begin()+1), res[i].end());
        }
        return res;


    }
};
