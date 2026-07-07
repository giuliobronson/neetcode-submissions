class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = 1, minEnding = 1;
        int res = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int temp = maxEnding;
            maxEnding = max({nums[i] * minEnding, nums[i] * maxEnding, nums[i]});
            minEnding = min({nums[i] * minEnding, nums[i] * temp, nums[i]});
            res = max(maxEnding, res);
        }

        return res;
    }
};
