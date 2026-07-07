class Solution {
public:
    int buildSegmentation(string s, vector<string>& wordDict, vector<int>& dp) {
        if (s.empty()) return 1;

        if (dp[s.length()] != -1) return dp[s.length()];

        for (auto& word: wordDict) {
            int len = word.size(); 
            if (s.substr(0, len) == word) {
                if (buildSegmentation(s.substr(len, s.length() - len), wordDict, dp)) {
                    dp[s.length()] = 1;
                    return dp[s.length()];
                }
            }
        }

        return dp[s.length()] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length() + 1, -1);
        return (bool) buildSegmentation(s, wordDict, dp);
    }
};
