class Solution {
public:
    int maximumAmountOfMoney(int i, int j, vector<int>& nums, vector<int>& dp) {
        if (i > j) return 0;

        if (dp[i] != -1) return dp[i];

        dp[i] = max(
            maximumAmountOfMoney(i + 2, j, nums, dp) + nums[i],
            maximumAmountOfMoney(i + 1, j, nums, dp)
        );

        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        
        vector<int> dp1(n + 1, -1), dp2(n + 1, -1);
        return max(maximumAmountOfMoney(1, n - 1, nums, dp1), maximumAmountOfMoney(0, n - 2, nums, dp2));
    }
};
