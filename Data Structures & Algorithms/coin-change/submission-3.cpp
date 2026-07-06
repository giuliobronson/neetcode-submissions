class Solution {
public:
    int change(vector<int>& coins, vector<vector<int>>& dp, int amount, int i) {
        if (amount < 0 || i >= coins.size()) return -1;
        if (amount == 0) return 0;

        if (dp[i][amount] != INT_MAX) return dp[i][amount];

        int take = change(coins, dp, amount - coins[i], i);
        int dont = change(coins, dp, amount, i + 1);

        if (take >= 0 && dont >= 0) return dp[i][amount] = min(take + 1, dont);
        if (take >= 0) return dp[i][amount] = take + 1;
        return dp[i][amount] = dont;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));
        return change(coins, dp, amount, 0);
    }
};
