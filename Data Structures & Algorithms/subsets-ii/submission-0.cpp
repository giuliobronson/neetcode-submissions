class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, i + 1);
        subset.pop_back();

        int j = i;
        while (j < nums.size() && nums[i] == nums[j]) j++;
        backtrack(nums, j);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }
};
