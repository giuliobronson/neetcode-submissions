class Solution {
public:
    int maxProd(vector<int>& dp, int n) {
        if (n <= 1) return 1;
        if (n == 2 || n == 3) {
            return dp[n] = n;
        }

        if (dp[n] != -1) return dp[n];

        return dp[n] = max(2 * maxProd(dp, n - 2), 3 * maxProd(dp ,n - 3));
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        if (n == 2 || n == 3) return n - 1;
        return maxProd(dp, n);
    }
};