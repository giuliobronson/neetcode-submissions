class Solution {
public:
    int sum, k, n;

    int makePartition(vector<int>& nums, vector<int>& dp, int mask, int acc) {
        if (sum % k || acc > sum) return 0;

        if (acc == sum) {
            if (mask == (1 << n) - 1) return 1;
            return dp[mask] = makePartition(nums, dp, mask, 0);
        }

        if (dp[mask] != -1) return dp[mask];

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;

            if (makePartition(nums, dp, mask | (1 << i), acc + k * nums[i])) {
                return dp[mask] = 1;
            }
        }

        return dp[mask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->sum = accumulate(nums.begin(), nums.end(), 0); 
        this->k = k; 
        this->n = nums.size();

        vector<int> dp((1 << n), -1);

        return (bool) makePartition(nums, dp, 0, 0);
    }
};