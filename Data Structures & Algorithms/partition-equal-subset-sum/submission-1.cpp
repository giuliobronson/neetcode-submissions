class Solution {
public:
    int choose(vector<int>& nums, vector<vector<int>>& dp, int sum, int i) {
        if (i >= nums.size() || sum < 0) {
            if (sum == 0) return 1;
            return 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        int one = choose(nums, dp, sum - nums[i] * 2, i + 1);
        int two = choose(nums, dp, sum, i + 1);

        return dp[i][sum] = one || two;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return (bool) choose(nums, dp, sum, 0);
    }
};
