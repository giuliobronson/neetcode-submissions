class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;
    unordered_set<int> processed;

    void backtrack(vector<int>& candidates, int target, int i, int sum) {
        if (sum == target) {
            res.push_back(combination);
            return;
        }
        if (sum > target || i >= candidates.size()) {
            return;
        }

        combination.push_back(candidates[i]); sum += candidates[i];
        backtrack(candidates, target, i + 1, sum);
        combination.pop_back(); sum -= candidates[i];
    
        int j = i;
        while (j < candidates.size() && candidates[j] == candidates[i]) j++;
        backtrack(candidates, target, j, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }
};
