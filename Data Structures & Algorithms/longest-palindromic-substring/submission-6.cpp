class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int n = s.length(), maxL = 1, start = 0;

        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxL) {
                        maxL  = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxL);
    }
};
