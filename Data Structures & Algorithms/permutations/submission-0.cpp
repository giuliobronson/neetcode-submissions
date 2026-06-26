class Solution {
public:
    vector<vector<int>> res;
    vector<int> permutation;
    unordered_set<int> inserted;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int n : nums) {
            if (inserted.count(n)) continue;
            permutation.push_back(n); inserted.insert(n);
            backtrack(nums, i + 1);
            permutation.pop_back(); inserted.erase(n);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
