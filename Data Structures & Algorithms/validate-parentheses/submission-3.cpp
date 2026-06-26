class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> st;

        for (char c : s) {
            if (m.count(c)) {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != m[c]) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            else {
                st.push(c);
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};
