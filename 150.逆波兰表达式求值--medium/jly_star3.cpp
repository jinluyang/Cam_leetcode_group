/*执行用时 :
20 ms
, 在所有 C++ 提交中击败了
42.56%
的用户
内存消耗 :
10.4 MB
, 在所有 C++ 提交中击败了
100.00%
的用户*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (isNumber(tokens[i]))
                s.push(atoi(tokens[i].c_str()));
            else {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = calculate(a,b,tokens[i]);
                //cout << res << ' ' << tokens[i] << endl;
                s.push(res);
            }
            
        }
        int res = s.top();
        //cout << s.size();

        return res;
    }
    int calculate(int a, int b, string c) {
        switch(c[0]) {
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':return a/b;
            default:
                assert(0);
                return -1;
        }
    }
    bool isNumber(string str) {
        if (str[0] == '*')
            return false;
        if (str[0] == '+')
            return false;
        if (str == "-")
            return false;
        if (str[0] == '/')
            return false;
        return true;
    }
};
