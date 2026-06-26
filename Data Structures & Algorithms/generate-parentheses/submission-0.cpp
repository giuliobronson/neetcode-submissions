class Solution {
public:
    vector<string> res;
    string parenthesis = "";

    bool isValidParenthesis(string& s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && c == ')' && st.top() == '(') st.pop();
            else st.push(c);
        }

        return st.empty();
    } 

    void backtrack(int n) {
        if (n == 0) {
            if (isValidParenthesis(parenthesis)) res.push_back(parenthesis);
            return;
        }

        parenthesis.push_back('(');
        backtrack(n - 1);
        parenthesis.pop_back();

        parenthesis.push_back(')');
        backtrack(n - 1);
        parenthesis.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        backtrack(2 * n);
        return res;
    }
};
