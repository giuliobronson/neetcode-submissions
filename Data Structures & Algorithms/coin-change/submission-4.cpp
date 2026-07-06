class Solution {
public:
    int change(vector<int>& coins, vector<int>& dp, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        if (dp[amount] != INT_MAX) return dp[amount];

        for (int coin : coins) {
            int c = change(coins, dp, amount - coin);
            if (c != -1 && c < dp[amount]) dp[amount] = c + 1;
        }

        return dp[amount] == INT_MAX ? dp[amount] = -1 : dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        return change(coins, dp, amount);
    }
};
