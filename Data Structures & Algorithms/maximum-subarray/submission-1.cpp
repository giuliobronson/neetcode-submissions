class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -INT_MAX;

        for (int i = 0, maxElement = -INT_MAX; i < nums.size(); i++) {
            if (maxElement < 0) maxElement = nums[i];
            else maxElement += nums[i];
            maxSum = max(maxElement, maxSum);
        }

        return maxSum;
    }
};
