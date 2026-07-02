class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;

        if (n == 0) return nums[0];

        vector<int> dp(nums.size() + 1, -1);

        dp[n] = nums[n]; 
        dp[n - 1] = max(nums[n - 1], nums[n]);
        
        for (int i = n; i >= 2; i--) {
            dp[i - 2] = max(dp[i - 1], dp[i] + nums[i - 2]);
        }

        return dp[0];
    }
};
