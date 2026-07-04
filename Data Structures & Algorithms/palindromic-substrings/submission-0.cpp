class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int count = 0;

        for (int len = 1; len <= s.length(); len++) {
            for (int i = 0; i + len - 1 < s.length(); i++) {
                if ((len <= 3 || dp[i + 1][i + len - 2]) && s[i] == s[i + len - 1]) {
                    dp[i][i + len - 1] = true;
                    count++;
                }
            }
        }

        return count;
    }
};
