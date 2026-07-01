class Solution {
public:
    int stepsNeeded(int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n <  0) return 0;

        if (dp[n] != -1) return dp[n];

        dp[n] = stepsNeeded(n - 1, dp) + stepsNeeded(n - 2, dp);

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return stepsNeeded(n, dp);
    }
};
