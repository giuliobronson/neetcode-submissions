class Solution {
public:
    int sum, k, n;

    bool makePartition(vector<int>& nums, int mask, int acc) {
        if (sum % k || acc > sum) return 0;

        if (acc == sum) {
            if (mask == (1 << n) - 1) return true;
            return makePartition(nums, mask, 0);
        }

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;

            if (makePartition(nums, mask | (1 << i), acc + k * nums[i])) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->sum = accumulate(nums.begin(), nums.end(), 0); 
        this->k = k; 
        this->n = nums.size();

        return (bool) makePartition(nums, 0, 0);
    }
};