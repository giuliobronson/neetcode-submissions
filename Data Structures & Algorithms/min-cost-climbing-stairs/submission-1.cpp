class Solution {
public:
    int backtrack(int floor, vector<int>& cost, vector<int>& dp) {
        if (floor >= cost.size()) {
            return 0;
        }

        if (dp[floor] != -1) return dp[floor];

        dp[floor] = min(
            backtrack(floor + 1, cost, dp),
            backtrack(floor + 2, cost, dp)
        ) + cost[floor];

        return dp[floor];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2, -1);
        return min(backtrack(0, cost, dp), backtrack(1, cost, dp));
    }
};
