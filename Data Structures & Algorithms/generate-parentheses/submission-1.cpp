class Solution {
public:
    vector<string> res;
    string parenthesis = "";

    void backtrack(int n, int open, int close) {
        if (open == n && close == n) {
            res.push_back(parenthesis);
            return;
        }

        if (open < n) {
            parenthesis.push_back('(');
            backtrack(n, open + 1, close);
            parenthesis.pop_back();
        }

        if (close < open) {
            parenthesis.push_back(')');
            backtrack(n, open, close + 1);
            parenthesis.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0);
        return res;
    }
};
