class Solution {
public: 
    vector<vector<int>> res;

    void include(vector<int>& subset, vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(vector<int>(subset.begin(), subset.end()));
            return;
        }
        
        subset.push_back(nums[i]);
        include(subset, nums, i + 1);

        subset.pop_back();
        include(subset, nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset = {};
        include(subset, nums, 0);
        return res;
    }
};
