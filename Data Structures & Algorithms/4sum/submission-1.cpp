class Solution {
public:
    vector<vector<int>> res;

    void makeSum(vector<int>& nums, vector<int>& quad, int i, long target) {
        if (target == 0 && quad.size() == 4) {
            res.push_back(quad);
            return;
        }

        if (quad.size() > 4 || i >= nums.size()) return;

        quad.push_back(nums[i]);
        makeSum(nums, quad, i + 1, target - nums[i]);
        quad.pop_back();

        int j = i;
        while (i < nums.size() && nums[i] == nums[j]) i++;
        
        makeSum(nums, quad, i, target);
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> quad;
        sort(nums.begin(), nums.end());
        makeSum(nums, quad, 0, target);
        return res;
    }
};