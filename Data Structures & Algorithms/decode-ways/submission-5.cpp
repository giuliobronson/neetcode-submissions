class Solution {
public:
    int decode(string& s, vector<int>& dp, int i){
        if (i >= s.length()) return 1;
        
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        dp[i] = decode(s, dp, i + 1);

        if (i + 1 < s.length() && stoi(s.substr(i, 2)) <= 26) {
            dp[i] += decode(s, dp, i + 2);
        }

        return dp[i];
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return decode(s, dp, 0);
    }
};
