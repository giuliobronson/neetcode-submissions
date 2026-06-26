class Solution {
public:
    vector<string> res;
    vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string digits, string buffer, int i) {
        if (digits.empty()) return;

        if (i >= digits.size()) {
            res.push_back(buffer);
            return;
        }

        for (char c : m[digits[i] - '0']) {
            buffer.push_back(c);
            backtrack(digits, buffer, i + 1);
            buffer.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        backtrack(digits, "", 0);
        return res;
    }
};
