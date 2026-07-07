class Solution {
public:
    int findWord(string& s, unordered_set<string>& words, vector<vector<int>>& dp, string buffer, int i, int j) {
        if (j == s.length() && !words.count(buffer)) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (words.count(buffer)) {
            if (j == s.length()) return 1;
            dp[i][j] = findWord(s, words, dp, string("") + s[j], j, j + 1);
        }

        return dp[i][j] = dp[i][j] <= 0 ? findWord(s, words, dp, buffer + s[j], i, j + 1) : dp[i][j];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));

        return (bool) findWord(s, words, dp, "", 0, 0);
    }
};
