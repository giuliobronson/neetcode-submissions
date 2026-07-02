class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() - 1;
        vector<int> dp(n + 1, -1);

        dp[n] = cost[n]; dp[n - 1] = cost[n - 1];
        for (int i = n; i >= 2; i--) {
            dp[i - 2] = min(dp[i], dp[i - 1]) + cost[i - 2];
        }

        return min(dp[0], dp[1]);
    }
};
