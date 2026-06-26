class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;

    void backtrack(vector<int>& nums, int target, int sum, int i) {
        if (sum  > target || i >= nums.size()) return;
        if (sum == target) {
            res.push_back(combination);
            return;
        }

        combination.push_back(nums[i]); sum += nums[i];
        backtrack(nums, target, sum, i);
        
        combination.pop_back(); sum -= nums[i];
        backtrack(nums, target, sum, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return res;
    }
};
