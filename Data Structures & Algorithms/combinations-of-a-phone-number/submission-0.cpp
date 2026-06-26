class Solution {
public:
    vector<string> res;
    unordered_map<int, vector<char>> m = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };

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
