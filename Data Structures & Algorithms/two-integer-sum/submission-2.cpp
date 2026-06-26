class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff = {};

        for (int i = 0; i < nums.size(); i++) {
            diff[target - nums[i]] = i;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (diff.count(nums[j]) && diff[nums[j]] != j) {
                return {j, diff[nums[j]]};
            }
        }
    }
};
