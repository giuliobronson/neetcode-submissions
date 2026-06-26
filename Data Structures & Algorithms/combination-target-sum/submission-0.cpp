class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;
    set<vector<int>> s;

    void backtrack(vector<int>& nums, int target, vector<int>& freq, int sum) {
        if (sum  > target || s.count(freq)) return;
        if (sum == target) {
            res.push_back(combination); s.insert(freq);
            return;
        }

        for (int n : nums) {
            combination.push_back(n); sum += n; freq[n]++;
            backtrack(nums, target, freq, sum);
            combination.pop_back(); sum -= n; freq[n]--;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> freq(target + 1, 0);
        backtrack(nums, target, freq, 0);
        return res;
    }
};
