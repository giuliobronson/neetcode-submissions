class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, int(*)(int, int)> op = {
            {"+", [](int a, int b){ return a + b; }},
            {"-", [](int a, int b){ return a - b; }},
            {"*", [](int a, int b){ return a * b; }},
            {"/", [](int a, int b){ return a / b; }}
        };

        for (string& s: tokens) {
            if (op.count(s)) {
                int second = st.top(); st.pop();
                int first  = st.top(); st.pop();
                st.push(op[s](first, second));
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
