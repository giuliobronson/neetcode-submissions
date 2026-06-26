class Solution {
public:
    vector<vector<string>> res;
    vector<string> palindromes;

    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        if (s.empty()) return false;

        while(l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }

        return true;
    }

    void backtrack(string s, string buffer, int i) {
        if (isPalindrome(buffer)) {
            palindromes.push_back(buffer);
            backtrack(s, "", i);

            if (i >= s.length()) res.push_back(palindromes);
            
            palindromes.pop_back();
        }

        if (i < s.length()) {
            buffer.push_back(s[i]);
            backtrack(s, buffer, i + 1);
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, "", 0);
        return res;
    }
};
