class Solution {
public:
    int maximumAmountOfMoney(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        dp[i] = max(
            maximumAmountOfMoney(i + 2, nums, dp) + nums[i],
            maximumAmountOfMoney(i + 1, nums, dp)
        );

        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, -1);
        return maximumAmountOfMoney(0, nums, dp);
    }
};
