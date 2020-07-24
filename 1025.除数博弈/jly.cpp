// 想复杂了，实际就跟奇偶有关
class Solution {
public:
    vector<int> getFactor(int N) {
        vector<int> res = {1};
        for (int i = 2; i <= N/2 + 1; i++) {
            if (N % i == 0)
                res.push_back(i);
        }
        return res;
    }
    bool divisorGame(int N) {
        vector<bool> result;
        result.push_back(false);
        result.push_back(false);//1
        result.push_back(true);//2
        for (int i = 3; i <= N; i++) {
            if (result[i-1] == false)
                result.push_back(true);
            else {
                //cout << "here";
                vector<int> factors = getFactor(i);
                bool found = false;
                for (int factor : factors) {
                    if (result[i-factor] == false) {
                        result.push_back(true);
                        found = true;
                    }
                }
                if (!found)
                    result.push_back(false);

            }

        }
        return result[N];
    }
};
