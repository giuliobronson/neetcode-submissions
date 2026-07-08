class Solution {
public:
    int choose(vector<int>& nums, vector<vector<int>>& dp, int i, int j) {
        if (j >= nums.size()) return 0;

        if (dp[i + 1][j] != -1) return dp[i + 1][j];

        int take = -1, dont = -1;
        if (i == -1 || nums[j] > nums[i]) {
            take = choose(nums, dp, j, j + 1);
        }
        dont = choose(nums, dp, i, j + 1);

        if (take >= 0 && dont >= 0) {
            return dp[i + 1][j] = max(take + 1, dont);
        }
        else if (take >= 0) {
            return dp[i + 1][j] = take + 1;
        }

        return dp[i + 1][j] = dont;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size(), -1));
        return choose(nums, dp, -1, 0);
    }
};
