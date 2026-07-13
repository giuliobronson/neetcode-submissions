class Solution {
public:
    int jump(vector<int>& nums, vector<int>& dp, int i) {
        if (i >= nums.size() - 1) return 1;

        if (dp[i] != -1) return dp[i];

        for (int j = nums[i]; j > 0; j--) {
            if (jump(nums, dp, i + j)) return 1;
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return (bool) jump(nums, dp, 0);
    }
};
