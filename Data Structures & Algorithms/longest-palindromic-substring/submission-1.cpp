class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int maxL = 0, start = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + maxL; j < s.length(); j++) {
                if (isPalindrome(s.substr(i, j - i + 1))) {
                    maxL = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxL);
    }
};
